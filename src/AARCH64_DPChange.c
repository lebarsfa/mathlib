/****************************************************************************/
/*                                                                          */
/*MODULE_NAME:DPChange                                                      */
/*                                                                          */
/*FUNCTIONS:Init_Lib                                                        */
/*          Exit_Lib                                                        */
/*                                                                          */
/* Init_lib must be called once prior to any usage of the mathlib routines. */
/* Exit_lib must be called once after the last usage of the mathlib         */
/* routines.                                                                */
/* Init_Lib changes the control word to IEEE double precision so that the   */
/* math routines will work properly. It returns the original status         */
/* as unsigned short. The returned value should be handed to Exit_lib       */
/* in order to restore the original status of the control word after the    */
/* math routines are no longer needed                                       */
/****************************************************************************/
#include "DPChange.h"
#include <stdio.h>
#if HAVE_FENV_H
#   include <fenv.h>
#endif /* HAVE_FENV_H */
#if defined(_WIN32)
#  include <float.h>
#  if !defined(_PC_53) || !defined(_MCW_PC)
/* 
Weird problem for MinGW, which sometimes prevents to use here 
_controlfp(_PC_53, _MCW_PC)...
*/
#undef _PC_53
#define _PC_53 0x00010000
#undef _MCW_EM
#define _MCW_EM 0x0008001f
#undef _MCW_RC
#define _MCW_RC 0x00000300
#undef _MCW_PC
#define _MCW_PC 0x00030000
#undef _MCW_IC
#define _MCW_IC 0x00040000
#undef _MCW_DN
#define _MCW_DN 0x03000000
#ifdef __cplusplus
extern "C" unsigned int _controlfp(unsigned int, unsigned int);
#else
extern int unsigned int _controlfp(unsigned int, unsigned int);
#endif
#  endif /* !defined(_PC_53) || !defined(_MCW_PC) */
#endif /* defined(_WIN32) */
/*
#define FESETENV fesetenv
#define FEGETENV fegetenv
*/
fenv_t mathlib_org_fenv;

/* Function to change precision control to double and round mode to nearest */
/* or even. Function returns unsigned short between 0 and 15 that indicates */
/* the original round control and precision mode before the change.         */
/* The two LSB bits of the returned value are the precision mode, and the   */
/* next two bits are the round control.                                     */

unsigned short Init_Lib()
{
#if HAVE_FENV_H
	/*
    FESETENV(FE_DFL_ENV); // round to nearest, all except. cleared, nonstop
    */
    feholdexcept(&mathlib_org_fenv);
    feclearexcept(FE_ALL_EXCEPT);
    fesetround(FE_TONEAREST);
/*
For ARM (and x86_64 Windows, Linux, Mac?), precision of double type is 
probably always IEEE 754 double and cannot be changed.
See https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/control87-controlfp-control87-2, 
http://christian-seiler.de/projekte/fpmath/, ARM C and C++ Libraries and 
Floating-Point Support User Guide.
*/
#   if defined(_WIN32) && (defined(_M_IX86) || defined(__i386__))
    _controlfp(_PC_53, _MCW_PC);
#   endif
    return 0; /* We do not try to save the fpu reg. before the call to Init_Lib() */
#else 
#   error "fenv.h not found and no replacement available to initialize the library"
#endif /* HAVE_FENV_H */
}


/* Function that receives an unsigned short argument in the range 0 - 15    */
/* and changes the precision control and round mode according to the        */
/* explanation above. If the value is more than 15 it prints to stdout an   */
/* error message and changes nothing.                                       */

void Exit_Lib(unsigned short status)
{
#if HAVE_FENV_H
	fesetenv(&mathlib_org_fenv);
  	return;
#else 
#   error "fenv.h not found and no replacement available to deinitialize the library"
#endif /* HAVE_FENV_H */
}
