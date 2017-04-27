# Copyright 2017 Stephen Lane-Walsh
# Licensed under the MIT License

# Find libcheck
#
# Output Variables
# - CHECK_FOUND
# - CHECK_INCLUDE_DIR
# - CHECK_LIBRARY
#

SET(
  CHECK_SEARCH_PATHS
  ${CHECK_PATH}
  # Unix
  /usr/local
  /usr
  /opt
  # OSX
  ~/Library/Frameworks
  /Library/Frameworks
  # Visual Studio
  $ENV{VS140COMNTOOLS}../../VC # VS 2015
  $ENV{VS120COMNTOOLS}../../VC # VS 2013
  $ENV{VS110COMNTOOLS}../../VC # VS 2012
  $ENV{VS100COMNTOOLS}../../VC # VS 2010
)

FIND_PATH(
  CHECK_INCLUDE_DIR
  NAMES check.h
  HINTS
  PATH_SUFFIXES include src
  PATHS ${CHECK_SEARCH_PATHS}
)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(PATH_SUFFIXES lib64 lib/x64 lib/amd64 lib)
else()
	set(PATH_SUFFIXES lib/x86 lib)
endif()

FIND_LIBRARY(
  CHECK_LIBRARY
  NAMES check
  HINTS
  PATH_SUFFIXES ${PATH_SUFFIXES}
  PATHS ${CHECK_SEARCH_PATHS}
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(
  check
  REQUIRED_VARS
  CHECK_INCLUDE_DIR
  CHECK_LIBRARY
)
