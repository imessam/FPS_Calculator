cmake_minimum_required(VERSION 3.15...3.31)

project(Common VERSION 1.0
                  DESCRIPTION "Common deps"
                  LANGUAGES CXX)


# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# CUDA
set(CUDA_TOOLKIT_ROOT_DIR "/usr/local/cuda")
find_package(CUDA 10.2 REQUIRED)

# set(CMAKE_CUDA_STANDARD 10.1)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)
# !CUDA

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
# !OpenCV



include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
