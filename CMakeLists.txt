cmake_minimum_required(VERSION 3.5)

project(MandelbrotSet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY ${CMAKE_SOURCE_DIR}/input DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include(${CMAKE_SOURCE_DIR}/src/CMakeLists.txt)

add_executable(Mandelbrot ${MANDELBROT_SOURCES})
find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
  message("OpenMP found.")
  target_link_libraries(Mandelbrot PUBLIC OpenMP::OpenMP_CXX)
  add_compile_options(-Wall -Wextra -Wpedantic)
  install(TARGETS Mandelbrot LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
else()
  message("OpenMP Not found. CMake ending...")
endif()

