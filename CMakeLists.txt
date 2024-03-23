###############################################################################
# MandelbrotSet                                                               #
#                                                                             #
# (C) Copyright 2024, Phil Underwood. All rights reserved.                    #
#                                                                             #
# This software is licensed under the terms of the 3-Clause BSD License       #
# which can be obtained from https://opensource.org/license/bsd-3-clause/.    #
###############################################################################

cmake_minimum_required(VERSION 3.5)

project(MandelbrotSet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

file(COPY ${CMAKE_SOURCE_DIR}/input DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
include(${CMAKE_SOURCE_DIR}/src/CMakeLists.txt)

find_package(OpenMP REQUIRED)

add_executable(Mandelbrot ${MANDELBROT_SOURCES})
add_compile_options(-Wall -Wextra -Wpedantic)
target_link_libraries(Mandelbrot PRIVATE OpenMP::OpenMP_CXX "/usr/local/lib/libraylib.a")
