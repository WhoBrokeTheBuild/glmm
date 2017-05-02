CMAKE_MINIMUM_REQUIRED(VERSION 3.2 FATAL_ERROR)

SET(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
SET(CMAKE_COLOR_MAKEFILE          ON)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

IF("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  MESSAGE(SEND_ERROR "In-source builds are not allowed.")
ENDIF()

IF(CMAKE_COMPILER_IS_GNUCC OR ${CMAKE_C_COMPILER_ID} MATCHES "Clang")
  SET(CMAKE_C_FLAGS " -std=c11 -Wall -Wextra -pedantic")
ENDIF()

FIND_PACKAGE(Check)

INCLUDE_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_BINARY_DIR}/include
)

SET(
  GLMM_INCLUDE
  "include/glmm/glmm.h"
  "include/glmm/plat.h"
  "include/glmm/const.h"
  "include/glmm/func.h"
  "include/glmm/vec.h"
  "include/glmm/vec.inl.h"
  "include/glmm/mat.h"
  "include/glmm/quat.h"
)

SET(
  GLMM_SRC
  "src/glmm.c"
)

ADD_EXECUTABLE(
  glmm_build
  ${GLMM_INCLUDE}
  ${GLMM_SRC}
)

INSTALL(FILES ${GLMM_INCLUDE} DESTINATION include/glmm)

IF(CHECK_FOUND)

  ENABLE_TESTING()
  INCLUDE_DIRECTORIES(${CHECK_INCLUDE_DIR})

  ADD_EXECUTABLE(
    vec_test
    tests/vec_test.c
  )
  TARGET_LINK_LIBRARIES(vec_test ${CHECK_LIBRARY})

  ADD_EXECUTABLE(
    quat_test
    tests/quat_test.c
  )
  TARGET_LINK_LIBRARIES(quat_test ${CHECK_LIBRARY})

  ADD_TEST("Vec" vec_test)
  ADD_TEST("Quat" quat_test)
ENDIF()

SOURCE_GROUP("Sources" FILES ${GLMM_INCLUDE} ${GLMM_SRC})

IF(UNIX)
  ADD_CUSTOM_TARGET(check COMMAND ${CMAKE_CTEST_COMMAND})

  ADD_CUSTOM_TARGET(
    format
    COMMENT "Formatting Source Files"
    COMMAND clang-format -i ${GLMM_INCLUDE} ${GLMM_SRC}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    SOURCES .clang-format
  )
ENDIF()
