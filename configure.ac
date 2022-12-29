# mathlib library version information
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# (shamelessly stolen from GiNaC (http://www.ginac.de/)
# Making releases:
#   mathlib_micro_version += 1;
#   mathlib_interface_age += 1;
#   mathlib_binary_age += 1;
# if any functions have been added, set mathlib_interface_age to 0.
# if backwards compatibility has been broken,
# set mathlib_binary_age and gaol_interface_age to 0.
# Version information for mathlib
m4_define([mathlib_major_version], [2])
m4_define([mathlib_minor_version], [1])
m4_define([mathlib_micro_version], [1])
m4_define([mathlib_version], ["mathlib_major_version.mathlib_minor_version.mathlib_micro_version"])
m4_define([mathlib_release], [mathlib_major_version.mathlib_minor_version])
m4_define([mathlib_interface_age], [0])
m4_define([mathlib_binary_age], [0])
dnl Version number. Do not forget to modify it also in AC_INIT() below
MATHLIB_MAJOR_VERSION=2
MATHLIB_MINOR_VERSION=1
MATHLIB_PATCH_VERSION=1
MATHLIB_RPM_RELEASE=1
MATHLIB_VERSION=${MATHLIB_MAJOR_VERSION}.${MATHLIB_MINOR_VERSION}.${MATHLIB_PATCH_VERSION}
AC_SUBST(MATHLIB_MAJOR_VERSION)
AC_SUBST(MATHLIB_MINOR_VERSION)
AC_SUBST(MATHLIB_MICRO_VERSION)
AC_SUBST(MATHLIB_RPM_RELEASE)

dnl Using a literal for the version number here, since
dnl newer versions of autoconf do not allow shell substitutions
AC_INIT([mathlib],[2.1.1])
AC_CONFIG_SRCDIR(src/MathLib.h)
dnl AC_PREREQ(2.13)

AM_MAINTAINER_MODE([disable])

AC_CONFIG_MACRO_DIR([m4])

dnl libtool versioning
m4_define([lt_revision], [mathlib_interface_age])
m4_define([lt_current], [m4_eval(mathlib_micro_version - mathlib_interface_age)])
m4_define([lt_age], [m4_eval(mathlib_binary_age - mathlib_interface_age)])
LT_VERSION_INFO="lt_current:lt_revision:lt_age"
LT_RELEASE="mathlib_release"

AC_SUBST(LT_VERSION_INFO)
AC_SUBST(LT_RELEASE)

LT_PREREQ([2.2.6])
LT_INIT([dlopen])

AC_C_BIGENDIAN

dnl options
AC_ARG_WITH(xlc,[ --with-xlc	Under AIX, use the xlc even if gcc exists])

AM_CONFIG_HEADER(src/mathlib_configuration.h)
AM_INIT_AUTOMAKE

dnl AC_PROG_MAKE_SET

dnl Determines the kind of architecture to use
AC_CANONICAL_HOST

# Testing existence of "-mpc64" compiler option

case "$host$" in
i?86-*-linux*)
	AC_DEFINE(MATHLIB_LINUX,1,
	          [Define this if your system is a linux based ix86 or compatible])
	AC_DEFINE(IX86_CPU,1,
				[Define this if your system is ix86-based]) 
	;;
*86_64-*-linux*)
	AC_DEFINE(MATHLIB_LINUX,1,
	          [Define this if your system is a linux based ix86 or compatible])
	AC_DEFINE(X86_64BITS,1,
		  [Define this if the OS is a 64 bits one])
	AC_DEFINE(IX86_CPU,1,
				[Define this if your system is ix86-based]) 
	;;
i?86-*-cygwin*)
	AC_DEFINE(MATHLIB_CYGWIN,1,
	          [Define this if your system is a cygwin based ix86 or compatible])
	AC_DEFINE(IX86_CPU,1,
				[Define this if your system is ix86-based]) 
	;;
*86_64-*-cygwin*)
	AC_DEFINE(MATHLIB_CYGWIN,1,
	          [Define this if your system is a cygwin based ix86 or compatible])
	AC_DEFINE(X86_64BITS,1,
		  [Define this if the OS is a 64 bits one])
	AC_DEFINE(IX86_CPU,1,
				[Define this if your system is ix86-based]) 
	;;
i?86-*-mingw*)
	AC_DEFINE(MATHLIB_MINGW,1,
	          [Define this if your system is a mingw based ix86 or compatible])
	AC_DEFINE(IX86_CPU,1,
				[Define this if your system is ix86-based]) 
	;;
*86_64-*-mingw*)
	AC_DEFINE(MATHLIB_MINGW,1,
	          [Define this if your system is a mingw based ix86 or compatible])
	AC_DEFINE(X86_64BITS,1,
		  [Define this if the OS is a 64 bits one])
	AC_DEFINE(IX86_CPU,1,
				[Define this if your system is ix86-based]) 
	;;
i?86-*-msys*)
	AC_DEFINE(MATHLIB_MINGW,1,
	          [Define this if your system is a mingw based ix86 or compatible])
	AC_DEFINE(IX86_CPU,1,
				[Define this if your system is ix86-based]) 
	;;
*86_64-*-msys*)
	AC_DEFINE(MATHLIB_MINGW,1,
	          [Define this if your system is a mingw based ix86 or compatible])
	AC_DEFINE(X86_64BITS,1,
		  [Define this if the OS is a 64 bits one])
	AC_DEFINE(IX86_CPU,1,
				[Define this if your system is ix86-based]) 
	;;
i?86-apple*)
	AC_DEFINE(MATHLIB_I86_MACOSX,1,
				[Define this if your system is a macOS-based ix86 or compatible])
	AC_DEFINE(IX86_CPU,1,
				[Define this if your system is ix86-based]) 
	;;
*86_64-apple*)
	AC_DEFINE(MATHLIB_I86_MACOSX,1,
				[Define this if your system is a macOS-based ix86 or compatible])
	AC_DEFINE(X86_64BITS,1,
		  [Define this if the OS is a 64 bits one])
	AC_DEFINE(IX86_CPU,1,
				[Define this if your system is ix86-based]) 
	;;
arm*-apple*)
	AC_DEFINE(MATHLIB_ARM_MACOSX,1,
				[Define this if your system is a macOS-based arm or compatible])
	;;
aarch64*-apple*)
	AC_DEFINE(MATHLIB_ARM_MACOSX,1,
				[Define this if your system is a macOS-based arm or compatible])
	AC_DEFINE(X86_64BITS,1,
		  [Define this if the OS is a 64 bits one])
	;;
rs6000-* | powerpc-*)
	AC_DEFINE(MATHLIB_AIX,1,
	          [Define this if your system is AIX based])
	;;
*-sun-*)
	AC_DEFINE(MATHLIB_SUN,1,
	          [Define this if your system is SUN based])
	;;
arm*-*-linux*)
	AC_DEFINE(MATHLIB_ARM,1,
		[Define this if your system is an arm-based computer under Linux])
	;;
aarch64*-*-linux*)
	AC_DEFINE(MATHLIB_AARCH64,1,
		[Define this if your system is an aarch64-based computer under Linux])
	AC_DEFINE(X86_64BITS,1,
		  [Define this if the OS is a 64 bits one])
	;;
*)
	AC_MSG_ERROR([Sorry, this system is not yet supported by mathlib])
esac

AC_CHECK_HEADERS([fenv.h])

CFLAGS="-g0 -O2 $CFLAGS"

# See # https://gcc.gnu.org/wiki/FloatingPointMath
# Checking for availability of -ffloat-store
AC_LANG([C])
OLD_CFLAGS=$CFLAGS
CFLAGS="-ffloat-store"
AC_MSG_CHECKING(whether the C compiler accepts -ffloat-store)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[]])],[has_ffloat_store_opt=yes],[has_ffloat_store_opt=no])
AC_MSG_RESULT(${has_ffloat_store_opt})
CFLAGS=${OLD_CFLAGS}
AC_LANG([C])
if test "${has_ffloat_store_opt}" = yes; then
    CFLAGS="${CFLAGS} -ffloat-store"
    AC_DEFINE(HAVE_FFLOAT_STORE_OPTION,1,
        [Define this to 1 if the compiler supports the "-ffloat-store" option])
fi

# See # https://gcc.gnu.org/wiki/FloatingPointMath
# Checking for availability of -frounding-math
AC_LANG([C])
OLD_CFLAGS=$CFLAGS
CFLAGS="-frounding-math"
AC_MSG_CHECKING(whether the C compiler accepts -frounding-math)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[]])],[has_frounding_math_opt=yes],[has_frounding_math_opt=no])
AC_MSG_RESULT(${has_frounding_math_opt})
CFLAGS=${OLD_CFLAGS}
AC_LANG([C])
if test "${has_frounding_math_opt}" = yes; then
    CFLAGS="${CFLAGS} -frounding-math"
    AC_DEFINE(HAVE_FROUNDING_MATH_OPTION,1,
        [Define this to 1 if the compiler supports the "-frounding-math" option])
fi

# See https://stackoverflow.com/questions/64036879/differing-floating-point-calculation-results-between-x86-64-and-armv8-2-a
# Checking for availability of -fno-fast-math
AC_LANG([C])
OLD_CFLAGS=$CFLAGS
CFLAGS="-fno-fast-math"
AC_MSG_CHECKING(whether the C compiler accepts -fno-fast-math)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[]])],[has_fno_fast_math_opt=yes],[has_fno_fast_math_opt=no])
AC_MSG_RESULT(${has_fno_fast_math_opt})
CFLAGS=${OLD_CFLAGS}
AC_LANG([C])
if test "${has_fno_fast_math_opt}" = yes; then
    CFLAGS="${CFLAGS} -fno-fast-math"
    AC_DEFINE(HAVE_FNO_FAST_MATH_OPTION,1,
        [Define this to 1 if the compiler supports the "-fno-fast-math" option])
fi

# See https://stackoverflow.com/questions/64036879/differing-floating-point-calculation-results-between-x86-64-and-armv8-2-a
# Checking for availability of -ffp-contract=off
AC_LANG([C])
OLD_CFLAGS=$CFLAGS
CFLAGS="-ffp-contract=off"
AC_MSG_CHECKING(whether the C compiler accepts -ffp-contract=off)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[]])],[has_ffp_contract_off_opt=yes],[has_ffp_contract_off_opt=no])
AC_MSG_RESULT(${has_ffp_contract_off_opt})
CFLAGS=${OLD_CFLAGS}
AC_LANG([C])
if test "${has_ffp_contract_off_opt}" = yes; then
    CFLAGS="${CFLAGS} -ffp-contract=off"
    AC_DEFINE(HAVE_FFP_CONTRACT_OFF_OPTION,1,
        [Define this to 1 if the compiler supports the "-ffp-contract=off" option])
fi

# See https://developer.arm.com/documentation/100067/0612/armclang-Command-line-Options/-ffp-mode
# Checking for availability of -ffp-mode=full
AC_LANG([C])
OLD_CFLAGS=$CFLAGS
CFLAGS="-ffp-mode=full"
AC_MSG_CHECKING(whether the C compiler accepts -ffp-mode=full)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[]])],[has_ffp_mode_full_opt=yes],[has_ffp_mode_full_opt=no])
AC_MSG_RESULT(${has_ffp_mode_full_opt})
CFLAGS=${OLD_CFLAGS}
AC_LANG([C])
if test "${has_ffp_mode_full_opt}" = yes; then
    CFLAGS="${CFLAGS} -ffp-mode=full"
    AC_DEFINE(HAVE_FFP_MODE_FULL_OPTION,1,
        [Define this to 1 if the compiler supports the "-ffp-mode=full" option])
fi

# See https://bugs.llvm.org/show_bug.cgi?id=8100
# Checking for availability of -fp-model=strict
AC_LANG([C])
OLD_CFLAGS=$CFLAGS
CFLAGS="-fp-model=strict"
AC_MSG_CHECKING(whether the C compiler accepts -fp-model=strict)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[]])],[has_fp_model_strict_opt=yes],[has_fp_model_strict_opt=no])
AC_MSG_RESULT(${has_fp_model_strict_opt})
CFLAGS=${OLD_CFLAGS}
AC_LANG([C])
if test "${has_fp_model_strict_opt}" = yes; then
    CFLAGS="${CFLAGS} -fp-model=strict"
    AC_DEFINE(HAVE_FP_MODEL_STRICT_OPTION,1,
        [Define this to 1 if the compiler supports the "-fp-model=strict" option])
fi

# See https://learn.microsoft.com/en-us/cpp/build/reference/fp-specify-floating-point-behavior
# Checking for availability of -fp:strict
AC_LANG([C])
OLD_CFLAGS=$CFLAGS
CFLAGS="-fp:strict"
AC_MSG_CHECKING(whether the C compiler accepts -fp:strict)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[]])],[has_fp_strict_opt=yes],[has_fp_strict_opt=no])
AC_MSG_RESULT(${has_fp_strict_opt})
CFLAGS=${OLD_CFLAGS}
AC_LANG([C])
if test "${has_fp_strict_opt}" = yes; then
    CFLAGS="${CFLAGS} -fp:strict"
    AC_DEFINE(HAVE_FP_STRICT_OPTION,1,
        [Define this to 1 if the compiler supports the "-fp:strict" option])
fi

# See https://stackoverflow.com/questions/7295861/enabling-strict-floating-point-mode-in-gcc
# Checking for availability of -mpc64
AC_LANG([C])
OLD_CFLAGS=$CFLAGS
CFLAGS="-mpc64"
AC_MSG_CHECKING(whether the C compiler accepts -mpc64)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[]])],[has_mpc64_opt=yes],[has_mpc64_opt=no])
AC_MSG_RESULT(${has_mpc64_opt})
CFLAGS=${OLD_CFLAGS}
AC_LANG([C])
if test "${has_mpc64_opt}" = yes; then
    CFLAGS="${CFLAGS} -mpc64"
    AC_DEFINE(HAVE_MPC64_OPTION,1,
        [Define this to 1 if the compiler supports the "-mpc64" option])
fi

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LIBTOOL

AC_PROG_MKDIR_P

AC_OUTPUT([Makefile src/Makefile mathlib.spec])
