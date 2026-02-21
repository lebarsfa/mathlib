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
#undef _PC_64
#define _PC_64 0x00000000
#undef _PC_53
#define _PC_53 0x00010000
#undef _PC_24
#define _PC_24 0x00020000
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
/*
fenv_t mathlib_org_fenv; // Global variables are not thread safe...?
*/

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
    /*
    feholdexcept(&mathlib_org_fenv);
    feclearexcept(FE_ALL_EXCEPT);
    fesetround(FE_TONEAREST);
    */
    unsigned short status = 0, precision_mode = 0, round_control = 0;
    switch (fegetround())
    {
    case FE_DOWNWARD:
	    round_control = 0x01;
	    break;
    case FE_UPWARD:
	    round_control = 0x02;
	    break;
    case FE_TOWARDZERO:
	    round_control = 0x03;
	    break;
    case FE_TONEAREST:
    default:
	    round_control = 0x00;
	    break;
    };
    fesetround(FE_TONEAREST);
/*
For ARM (and x86_64 Windows, Linux, Mac?), precision of double type is 
probably always IEEE 754 double and cannot be changed (or possibly only with  compilation flags...?).
See https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/control87-controlfp-control87-2, 
http://christian-seiler.de/projekte/fpmath/, ARM C and C++ Libraries and 
Floating-Point Support User Guide.
*/
#   if defined(_WIN32) && (defined(_M_IX86) || defined(__i386__))
    unsigned int cw = _controlfp(0u, 0u); /* Be careful: this is not exactly _Fe_ctl from fenv_t. 
                                             Precision bits seem to be at bits 12 and 13 in _Fe_ctl instead of 16 and 17 in cw... */
    unsigned int pc = cw & _MCW_PC; /* Extract precision bits */ 
    precision_mode = (unsigned short)(pc >> 16);
    _controlfp(_PC_53, _MCW_PC); /* Set x87 precision to 53-bit (double) */
#   endif
    status = ((round_control & 0x03) << 2) | (precision_mode & 0x03);
    return status; /* Try to save the fpu reg. before the call to Init_Lib() */
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
    /*
    fesetenv(&mathlib_org_fenv);
    */
    if (status > 15) /* unsigned is always greater than zero */
    {
        printf("Exit_Lib: argument > 15 error, status=%d\n", status);
        return;
    }
/*
For ARM (and x86_64 Windows, Linux, Mac?), precision of double type is 
probably always IEEE 754 double and cannot be changed.
See https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/control87-controlfp-control87-2, 
http://christian-seiler.de/projekte/fpmath/, ARM C and C++ Libraries and 
Floating-Point Support User Guide.
*/
#   if defined(_WIN32) && (defined(_M_IX86) || defined(__i386__))
    {
        /* Extract saved precision mode (two LSB) */
        unsigned short precision_mode = (unsigned short)(status & 0x03);
        unsigned int pc = ((unsigned int)precision_mode) << 16;
        _controlfp(pc, _MCW_PC);
    }
#   endif
    /* Extract saved round control (3rd and 4th bits) */
    unsigned short round_control = (unsigned short)((status >> 2) & 0x03);
    /* Restore rounding mode */
    int round_mode = 0;
    switch (round_control)
    {
    case 0x01:
        round_mode = FE_DOWNWARD;
        break;
    case 0x02:
        round_mode = FE_UPWARD;
        break;
    case 0x03:
        round_mode = FE_TOWARDZERO;
        break;
    case 0x00:
    default:
        round_mode = FE_TONEAREST;
        break;
    }
    (void)fesetround(round_mode);
    return;
#else 
#   error "fenv.h not found and no replacement available to deinitialize the library"
#endif /* HAVE_FENV_H */
}
