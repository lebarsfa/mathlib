/*
 * IBM Accurate Mathematical Library
 * Copyright (c) International Business Machines Corp., 2001
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or 
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  
 */
/********************************************************************/
/* Ultimate math functions. Each function computes the exact        */
/* theoretical value of its argument rounded to nearest or even.    */
/*                                                                  */
/* Assumption: Machine arithmetic operations are performed in       */
/* round nearest mode of IEEE 754 standard.                         */
/********************************************************************/

#ifndef UMATH_LIB
#define UMATH_LIB

#include "mathlib_config.h"

/********************************************************************/
/* Function changes the precision mode to IEEE 754 double precision */
/* and the rounding mode to nearest or even.                        */
/* It returns the original status of these modes.                   */
/* See further explanations of usage in DPChange.h                  */
/********************************************************************/

EXTERN_C MATHLIB_EXPORT unsigned short Init_Lib();

/********************************************************************/
/* Function that changes the precision and rounding modes to the    */
/* specified by the argument received. See further explanations in  */
/* DPChange.h                                                       */
/********************************************************************/
EXTERN_C MATHLIB_EXPORT  void Exit_Lib(unsigned short);


/* The  asin() function calculates the arc sine of its argument.    */
/* The  function returns the arc sine in radians                    */
/* (between -PI/2 and PI/2).                                        */
/* If the argument is greater than 1 or less than -1 it returns     */
/* a NaN.                                                           */
EXTERN_C MATHLIB_EXPORT  double uasin(double );


/* The  acos() function calculates the arc cosine of its argument.  */
/* The  function returns the arc cosine in radians                  */
/* (between -PI/2 and PI/2).                                        */
/* If the argument is greater than 1 or less than -1 it returns     */
/* a NaN.                                                           */
EXTERN_C MATHLIB_EXPORT  double uacos(double );

/* The  atan() function calculates the arctanget of its argument.   */
/* The  function returns the arc tangent in radians                 */
/* (between -PI/2 and PI/2).                                        */
EXTERN_C MATHLIB_EXPORT  double uatan(double );


/* The uatan2() function calculates the arc tangent of the two arguments x   */
/* and y (x is the right argument and y is the left one).The signs of both   */
/* arguments are used to determine the quadrant of the result.               */
/* The function returns the result in radians, which is between -PI and PI   */
EXTERN_C MATHLIB_EXPORT  double uatan2(double ,double ); 

/* Compute log(x). The base of log is e (natural logarithm)         */
EXTERN_C MATHLIB_EXPORT  double ulog(double );

/* Compute log2(x).                                                  */
EXTERN_C MATHLIB_EXPORT  double ulog2(double );

/* Compute e raised to the power of argument x.                     */
EXTERN_C MATHLIB_EXPORT  double uexp(double );

/* Compute 2 raised to the power of argument x.                     */
EXTERN_C MATHLIB_EXPORT  double uexp2(double );

/* Compute sin(x). The argument x is assumed to be given in radians.*/
EXTERN_C MATHLIB_EXPORT  double usin(double );

/* Compute cos(x). The argument x is assumed to be given in radians.*/
EXTERN_C MATHLIB_EXPORT double ucos(double );

/* Compute tan(x). The argument x is assumed to be given in radians.*/
EXTERN_C MATHLIB_EXPORT double utan(double );

/* Compute cotan(x). The argument x is assumed to be given in radians.*/
EXTERN_C MATHLIB_EXPORT double ucot(double );

/* Compute the square root of non-negative argument x.              */
/* If x is negative the returned value is NaN.                      */
EXTERN_C MATHLIB_EXPORT double usqrt(double );

/* Compute x raised to the power of y, where x is the left argument */
/* and y is the right argument. The function returns a NaN if x<0.  */
/* If x equals zero it returns -inf                                 */
EXTERN_C MATHLIB_EXPORT double upow(double , double );

/* Computing x mod y, where x is the left argument and y is the     */
/* right one.                                                       */
EXTERN_C MATHLIB_EXPORT double uremainder(double , double );

#endif
