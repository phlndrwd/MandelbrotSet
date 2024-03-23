###############################################################################
# MandelbrotSet                                                               #
#                                                                             #
# (C) Copyright 2024, Phil Underwood. All rights reserved.                    #
#                                                                             #
# This software is licensed under the terms of the 3-Clause BSD License       #
# which can be obtained from https://opensource.org/license/bsd-3-clause/.    #
###############################################################################

list(APPEND MANDELBROT_SOURCES
  ${CMAKE_CURRENT_LIST_DIR}/Colour.cpp
  ${CMAKE_CURRENT_LIST_DIR}/Colour.h
  ${CMAKE_CURRENT_LIST_DIR}/ColourMaps.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ColourMaps.h
  ${CMAKE_CURRENT_LIST_DIR}/FileReader.cpp
  ${CMAKE_CURRENT_LIST_DIR}/FileReader.h
  ${CMAKE_CURRENT_LIST_DIR}/ImageProcessor.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ImageProcessor.h
  ${CMAKE_CURRENT_LIST_DIR}/ImageWriter.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ImageWriter.h
  ${CMAKE_CURRENT_LIST_DIR}/Main.cpp
  ${CMAKE_CURRENT_LIST_DIR}/MandelbrotSet.cpp
  ${CMAKE_CURRENT_LIST_DIR}/MandelbrotSet.h
)
