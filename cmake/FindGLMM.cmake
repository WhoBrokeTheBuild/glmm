# Copyright 2017 Stephen Lane-Walsh
# Licensed under the MIT License

# Find the GLMM Include Files
#
# Output Variables
# - GLMM_FOUND
# - GLMM_INCLUDE_DIR
#

SET(
  GLMM_SEARCH_PATHS
  ${GLMM_PATH}
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
  GLMM_INCLUDE_DIR
  NAMES glmm/glmm.h
  HINTS
  PATH_SUFFIXES include src
  PATHS ${GLMM_SEARCH_PATHS}
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(
  glmm
  REQUIRED_VARS
  GLMM_INCLUDE_DIR
)
