cmake_minimum_required(VERSION 3.5)

project(MandelbrotSet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY ${CMAKE_SOURCE_DIR}/input DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
include(${CMAKE_SOURCE_DIR}/src/CMakeLists.txt)

find_package(OpenMP REQUIRED)

add_executable(Mandelbrot ${MANDELBROT_SOURCES})
add_compile_options(-Wall -Wextra -Wpedantic)
target_link_libraries(Mandelbrot PRIVATE OpenMP::OpenMP_CXX)
target_link_directories(Mandelbrot PUBLIC)
