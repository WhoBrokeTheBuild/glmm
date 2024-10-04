cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

list(PREPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

project(glmm)

option(GLMM_BUILD_TESTS OFF)

set(
  _include_list
  "include/glmm/glmm.h"
  "include/glmm/plat.h"
  "include/glmm/const.h"
  "include/glmm/func.h"
  "include/glmm/vec.h"
  "include/glmm/vec.inl.h"
  "include/glmm/mat.h"
  "include/glmm/quat.h"
)

set(
  _source_list
  "src/glmm.c"
)

add_executable(
  glmm_build
  ${_include_list}
  ${_source_list}
)

target_include_directories(
    glmm_build
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install(FILES ${GLMM_INCLUDE} DESTINATION include/glmm)

if(GLMM_BUILD_TESTS)
    find_package(Check)

    enable_testing()
    include_directories(${CHECK_INCLUDE_DIR})

    add_executable(
        vec_test
        tests/vec_test.c
    )
    target_link_libraries(vec_test ${CHECK_LIBRARY})

    add_executable(
        quat_test
        tests/quat_test.c
    )
    target_link_libraries(quat_test ${CHECK_LIBRARY})

    add_test("Vec" vec_test)
    add_test("Quat" quat_test)
endif()

add_library(glmm INTERFACE)

target_include_directories(
    glmm
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)