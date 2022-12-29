#undef PACKAGE
#undef VERSION

#ifndef _MATHLIB_DLL_
#   if defined(_MSC_VER)
#      define _MATHLIB_DLL_ extern __declspec(dllexport)
#   else
#      define _MATHLIB_DLL_
#   endif
#endif /* _MATHLIB_DLL_ */

/* Try to be more independent from autotools to simplify compatibility with other build systems */

/* See https://devblogs.microsoft.com/cppblog/c99-library-support-in-visual-studio-2013/ 
for information about new headers to get Visual Studio closer to C99...
See also https://learn.microsoft.com/en-us/cpp/build/reference/zc-cplusplus. */
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || (__cplusplus >= 201103L) || (defined(_MSC_VER) && (_MSC_VER >= 1800))
#   ifndef HAVE_FENV_H
#      define HAVE_FENV_H 1
#   endif
#else
/* Rely on autotools */
#   include "mathlib_configuration.h"
#endif

#if defined(_MSC_VER)
#   pragma fenv_access(on)
#else
#   pragma STDC FENV_ACCESS on
#endif

/* Name of package */
#ifndef PACKAGE
#   define PACKAGE "mathlib"
#endif

/* Version number of package */
#ifndef VERSION
#   define VERSION "2.1.2"
#endif
