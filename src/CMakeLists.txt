# From https://gitlab.com/CLIUtils/modern-cmake/-/blob/b47192867e86e5f00f70ec860638a28473edc8bf/examples/extended-project/src/CMakeLists.txt

# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${mathlib_SOURCE_DIR}/include/modern/*.hpp")
#set(HEADER_LIST "${mathlib_SOURCE_DIR}/include/modern/lib.hpp")
set(SOURCE_LIST 
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
utan.c)
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${mathlib_SOURCE_DIR}/src/*.h")
file(GLOB TABLE_LIST CONFIGURE_DEPENDS "${mathlib_SOURCE_DIR}/src/*.tbl")

# Make an automatic library - will be static or dynamic based on user setting
add_library(ultim ${SOURCE_LIST} ${HEADER_LIST} ${TABLE_LIST})

# Inspired from https://unclejimbo.github.io/2018/06/08/Modern-CMake-for-Library-Developers/
add_library(mathlib::ultim ALIAS ultim)

# We need this directory, and users of our library will need it too
# Inspired from https://unclejimbo.github.io/2018/06/08/Modern-CMake-for-Library-Developers/
target_include_directories(ultim 
	PUBLIC
		"$<INSTALL_INTERFACE:include>"
		"$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/src>"
		"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)

# See https://github.com/friendlyanon/cxx-static-shared-example
include(GenerateExportHeader)
generate_export_header(
    ultim
    BASE_NAME mathlib
    EXPORT_FILE_NAME mathlib_configuration.h
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(ultim PUBLIC mathlib_STATIC_DEFINE)
else()
  target_compile_definitions(ultim PUBLIC mathlib_SHARED_DEFINE) # For compatibility...
endif()

#if(MSVC)
#  #target_compile_options(ultim PUBLIC -fp:strict)
#  add_compile_options(-fp:strict)
#else()
  include(CheckCCompilerFlag)
  check_c_compiler_flag ("-frounding-math" C_COMPILER_SUPPORTS_FROUNDING_MATH)
  if(C_COMPILER_SUPPORTS_FROUNDING_MATH)
    #target_compile_options(ultim PUBLIC -frounding-math)
    add_compile_options(-frounding-math)
  endif()
  check_c_compiler_flag ("-ffloat-store" C_COMPILER_SUPPORTS_FFLOAT_STORE)
  if(C_COMPILER_SUPPORTS_FFLOAT_STORE)
    #target_compile_options(ultim PUBLIC -ffloat-store)
    add_compile_options(-ffloat-store)
  endif()
  check_c_compiler_flag ("-fno-fast-math" C_COMPILER_SUPPORTS_FNO_FAST_MATH)
  if(C_COMPILER_SUPPORTS_FNO_FAST_MATH)
    #target_compile_options(ultim PUBLIC -fno-fast-math)
    add_compile_options(-fno-fast-math)
  endif()
  check_c_compiler_flag ("-ffp-contract=off" C_COMPILER_SUPPORTS_FFP_CONTRACT_OFF)  
  if(C_COMPILER_SUPPORTS_FFP_CONTRACT_OFF)
    #target_compile_options(ultim PUBLIC -ffp-contract=off)
    add_compile_options(-ffp-contract=off)
  endif()
  check_c_compiler_flag ("-ffp-mode=full" C_COMPILER_SUPPORTS_FFP_MODE_FULL)  
  if(C_COMPILER_SUPPORTS_FFP_MODE_FULL)
    #target_compile_options(ultim PUBLIC -ffp-mode=full)
    add_compile_options(-ffp-mode=full)
  endif()
  check_c_compiler_flag ("-fp-model=strict" C_COMPILER_SUPPORTS_FP_MODEL_STRICT)  
  if(C_COMPILER_SUPPORTS_FP_MODEL_STRICT)
    #target_compile_options(ultim PUBLIC -fp-model=strict)
    add_compile_options(-fp-model=strict)
  endif()
  check_c_compiler_flag ("-fp:strict" C_COMPILER_SUPPORTS_FP_STRICT)  
  if(C_COMPILER_SUPPORTS_FP_STRICT)
    #target_compile_options(ultim PUBLIC -fp:strict)
    add_compile_options(-fp:strict)
  endif()
  check_c_compiler_flag ("-mpc64" C_COMPILER_SUPPORTS_MPC64)  
  if(C_COMPILER_SUPPORTS_MPC64)
    #target_compile_options(ultim PUBLIC -mpc64)
    add_compile_options(-mpc64)
  endif()
#endif()

# IDEs should put the headers in a nice place
#source_group(
#  TREE "${PROJECT_SOURCE_DIR}/include"
#  PREFIX "Header Files"
#  FILES ${HEADER_LIST})
source_group(
  TREE "${PROJECT_SOURCE_DIR}/src"
  PREFIX "Table Files"
  FILES ${TABLE_LIST})
