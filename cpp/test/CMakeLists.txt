cmake_minimum_required(VERSION 3.15...3.31)

project(FPSCalculatorTest VERSION 1.0
                  DESCRIPTION "FPS Calculator Test"
                  LANGUAGES CXX)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/common.cmake)

enable_testing()

add_executable(
  fps_calculator_test

  ${CMAKE_CURRENT_LIST_DIR}/test_main.cpp

  ${CMAKE_CURRENT_LIST_DIR}/test_fps.cpp
)

target_include_directories(fps_calculator_test PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)

target_link_libraries(
  fps_calculator_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(fps_calculator_test)
