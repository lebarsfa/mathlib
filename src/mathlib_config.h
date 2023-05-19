#undef PACKAGE
#undef VERSION

#ifndef EXTERN_C
#   ifdef __cplusplus
#      define EXTERN_C extern "C"
#   else
#      define EXTERN_C extern 
#   endif /* __cplusplus */
#endif /* !EXTERN_C */

#ifdef DISABLE_MATHLIB_CONFIGURATION_H
/* See https://github.com/friendlyanon/cxx-static-shared-example, https://gitlab.kitware.com/cmake/cmake/-/issues/16370, 
https://gcc.gnu.org/wiki/Visibility, https://learn.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp */
#ifndef MATHLIB_EXPORT
#   if defined(MATHLIB_STATIC_DEFINE) || !defined(MATHLIB_SHARED_DEFINE)
#      define MATHLIB_EXPORT
#   else
#      if defined(_WIN32) || defined(__CYGWIN__)
#         ifdef MATHLIB_EXPORTS
#            define MATHLIB_EXPORT __declspec(dllexport)
#         else
#            define MATHLIB_EXPORT __declspec(dllimport)
#         endif /* MATHLIB_EXPORTS */
#      else
#         define MATHLIB_EXPORT
#      endif /* defined(_WIN32) || defined(__CYGWIN__) */
#   endif /* defined(MATHLIB_STATIC_DEFINE) || !defined(MATHLIB_SHARED_DEFINE) */
#endif /* !MATHLIB_EXPORT */
#else
/* See https://github.com/friendlyanon/cxx-static-shared-example */
#include "mathlib_configuration.h"
#endif /* DISABLE_MATHLIB_CONFIGURATION_H */

/* Compatibility with existing code */
#ifdef _MATHLIB_DLL_
#   undef EXTERN_C
#   define EXTERN_C
#   undef MATHLIB_EXPORT
#   define MATHLIB_EXPORT _MATHLIB_DLL_
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
/*#   include "mathlib_configuration.h"*/
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
