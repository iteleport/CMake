# a simple C only test case
cmake_minimum_required (VERSION 2.6)
project (CompileCommandOutput CXX)

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_DEBUG_POSTFIX "_test_debug_postfix")
IF(MAKE_SUPPORTS_SPACES)
  SET(test1_srcs "file with spaces.cxx")
ELSE()
  SET(test1_srcs "file_with_underscores.cxx")
ENDIF()
ADD_LIBRARY(test1 STATIC ${test1_srcs})
ADD_LIBRARY(test2 SHARED "../CompileCommandOutput/relative.cxx")
INCLUDE_DIRECTORIES(${CompileCommandOutput_SOURCE_DIR}/../../Source)
ADD_EXECUTABLE(CompileCommandOutput compile_command_output.cxx)
TARGET_LINK_LIBRARIES(CompileCommandOutput test1 test2)
