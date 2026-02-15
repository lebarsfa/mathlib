#include "mathlib_config.h"

/*
See https://sourceforge.net/p/predef/wiki/Home/,
https://learn.microsoft.com/en-us/cpp/preprocessor/predefined-macros
*/
#if defined(__linux__) && defined(__x86_64__)
#   if HAVE_FENV_H
#      include "LINUX64_DPChange.c"
#   else
#      include "LINUX_DPChange.c"
#   endif /* HAVE_FENV_H */
#elif defined(__linux__) && defined(__i386__)
#   include "LINUX_DPChange.c"
#elif defined(__APPLE__) && defined(__x86_64__)
#   if HAVE_FENV_H
#      include "LINUX64_DPChange.c"
#   else
#      include "LINUX_DPChange.c"
#   endif /* HAVE_FENV_H */
#elif (defined(_MSC_VER) || defined(__BORLANDC__))
#   if HAVE_FENV_H
#      include "AARCH64_DPChange.c"
#   else
#      include "MSVC_DPChange.c"
#   endif /* HAVE_FENV_H */
#elif defined(__MINGW32__)
/* https://sourceforge.net/p/mingw-w64/bugs/541/ ? */
#   if HAVE_FENV_H
#      include "AARCH64_DPChange.c"
#   else
#      include "LINUX_DPChange.c"
#   endif /* HAVE_FENV_H */
#else
#   if HAVE_FENV_H
#      include "AARCH64_DPChange.c"
#   else
#      include "LINUX_DPChange.c"
#   endif /* HAVE_FENV_H */
#endif
