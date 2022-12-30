# From https://gitlab.com/CLIUtils/modern-cmake/-/blob/b47192867e86e5f00f70ec860638a28473edc8bf/examples/extended-project/src/CMakeLists.txt

# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${mathlib_SOURCE_DIR}/include/modern/*.hpp")
#set(HEADER_LIST "${mathlib_SOURCE_DIR}/include/modern/lib.hpp")
file(GLOB OTHER_SOURCES_AND_HEADERS_LIST CONFIGURE_DEPENDS "${mathlib_SOURCE_DIR}/*.h" "${mathlib_SOURCE_DIR}/*.tbl")

# Make an automatic library - will be static or dynamic based on user setting
add_library(ultim 
atnat.c
atnat2.c
branred.c
doasin.c
dosincos.c
DPChange.c
halfulp.c
mpa.c
mpatan.c
mpatan2.c
mpexp.c
mplog.c
mpsqrt.c
mptan.c
sincos32.c
slowcot.c
slowexp.c
slowexp2.c
slowlog2.c
slowpow.c
uasncs.c
ucot.c
uexp.c
uexp2.c
ulog.c
ulog2.c
upow.c
urem.c
uroot.c
usncs.c
utan.c
${OTHER_SOURCES_AND_HEADERS_LIST})


# We need this directory, and users of our library will need it too
#target_include_directories(ultim PUBLIC ../include)

# This depends on (header only) boost
#target_link_libraries(ultim PRIVATE Boost::boost)

# All users of this library will need at least C++11
#target_compile_features(ultim PUBLIC cxx_std_11)

include(CheckCCompilerFlag)
check_c_compiler_flag ("-frounding-math" COMPILER_SUPPORTS_FROUNDING_MATH)
if (COMPILER_SUPPORTS_FROUNDING_MATH)
  target_compile_options(ultim PUBLIC "-frounding-math")
endif ()
check_c_compiler_flag ("-ffloat-store" COMPILER_SUPPORTS_FFLOAT_STORE)
if (COMPILER_SUPPORTS_FFLOAT_STORE)
  target_compile_options(ultim PUBLIC "-ffloat-store")
endif ()
check_c_compiler_flag ("-fno-fast-math" COMPILER_SUPPORTS_FNO_FAST_MATH)
if (COMPILER_SUPPORTS_FNO_FAST_MATH)
  target_compile_options(ultim PUBLIC "-fno-fast-math")
endif ()
check_c_compiler_flag ("-ffp-contract=off" COMPILER_SUPPORTS_FFP_CONTRACT_OFF)  
if (COMPILER_SUPPORTS_FFP_CONTRACT_OFF)
  target_compile_options(ultim PUBLIC "-ffp-contract=off")
endif ()
check_c_compiler_flag ("-ffp-mode=full" COMPILER_SUPPORTS_FFP_MODE_FULL)  
if (COMPILER_SUPPORTS_FFP_MODE_FULL)
  target_compile_options(ultim PUBLIC "-ffp-mode=full")
endif ()
check_c_compiler_flag ("-fp-model=strict" COMPILER_SUPPORTS_FP_MODEL_STRICT)  
if (COMPILER_SUPPORTS_FP_MODEL_STRICT)
  target_compile_options(ultim PUBLIC "-fp-model=strict")
endif ()
check_c_compiler_flag ("-fp:strict" COMPILER_SUPPORTS_FP_STRICT)  
if (COMPILER_SUPPORTS_FP_STRICT)
  target_compile_options(ultim PUBLIC "-fp:strict")
endif ()
check_c_compiler_flag ("-mpc64" COMPILER_SUPPORTS_MPC64)  
if (COMPILER_SUPPORTS_MPC64)
  target_compile_options(ultim PUBLIC "-mpc64")
endif ()

# IDEs should put the headers in a nice place
#source_group(
#  TREE "${PROJECT_SOURCE_DIR}/include"
#  PREFIX "Header Files"
#  FILES ${HEADER_LIST})
