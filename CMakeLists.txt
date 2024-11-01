# From https://gitlab.com/CLIUtils/modern-cmake/-/blob/b47192867e86e5f00f70ec860638a28473edc8bf/examples/extended-project/CMakeLists.txt

# Works with 3.14 and tested through 3.25
cmake_minimum_required(VERSION 3.14...3.25)

# Project name and a few useful settings. Other commands can pick up the results
project(
  mathlib
  VERSION 2.1.2
  DESCRIPTION "IBM Accurate Portable Mathlib"
  LANGUAGES C)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  option(BUILD_SHARED_LIBS "Build shared libs" OFF)
  if(NOT BUILD_SHARED_LIBS)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
  endif()

endif()

# The compiled library code is here
add_subdirectory(src)

# From https://gitlab.com/CLIUtils/modern-cmake/-/blob/b47192867e86e5f00f70ec860638a28473edc8bf/chapters/install/installing.md
# and https://unclejimbo.github.io/2018/06/08/Modern-CMake-for-Library-Developers/
install(TARGETS ultim
        EXPORT mathlibTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
#        RUNTIME DESTINATION bin
#        INCLUDES DESTINATION include
        )

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/MathLib.h ${CMAKE_CURRENT_SOURCE_DIR}/src/mathlib_config.h ${CMAKE_CURRENT_BINARY_DIR}/src/mathlib_configuration.h
    DESTINATION include
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    mathlibConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY AnyNewerVersion
    )
  
# Inspired from https://github.com/fmtlib/fmt/blob/7d4662f7ab39f70107b6e8899bcc4076fe947a39/CMakeLists.txt
export(TARGETS ultim NAMESPACE mathlib::
        FILE mathlibTargets.cmake)

install(EXPORT mathlibTargets
        #FILE mathlibTargets.cmake
        NAMESPACE mathlib::
        DESTINATION share/cmake/mathlib
         )

configure_file(mathlibConfig.cmake.in mathlibConfig.cmake @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/mathlibConfig.cmake"
              "${CMAKE_CURRENT_BINARY_DIR}/mathlibConfigVersion.cmake"
        DESTINATION share/cmake/mathlib
        )