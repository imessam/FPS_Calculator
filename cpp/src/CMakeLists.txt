cmake_minimum_required(VERSION 3.15...3.31)

project(FPSCalculator VERSION 1.0
                  DESCRIPTION "FPS Calculator Module"
                  LANGUAGES CXX)

## Libraries setup

set(FPS_CALCULATOR_SOURCES
  ${CMAKE_CURRENT_LIST_DIR}/fps.cpp
)

if (NOT TARGET FPSCalculatorLib)

  add_library(FPSCalculatorLib STATIC ${FPS_CALCULATOR_SOURCES})

  target_include_directories(FPSCalculatorLib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)

endif()
