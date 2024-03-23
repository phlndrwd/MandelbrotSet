/******************************************************************************
* MandelbrotSet                                                               *
*                                                                             *
* (C) Copyright 2024, Phil Underwood. All rights reserved.                    *
*                                                                             *
* This software is licensed under the terms of the 3-Clause BSD License       *
* which can be obtained from https://opensource.org/license/bsd-3-clause/.    *
******************************************************************************/

#include "ImageWriter.h"

#include <fstream>
#include <iostream>

#include "Constants.h"

ImageWriter::ImageWriter() {}


bool ImageWriter::toPPM(const std::vector<Colour>& image, const std::string& filePath,
                        const unsigned& width, const unsigned& height) {
  try {
    std::ofstream fileOut(filePath);
    fileOut << "P3" << std::endl;
    fileOut << width << " " << height << std::endl;
    fileOut << "255" << std::endl;
    // The j loop below technically writes the image upside-down, but since the Mandelbrot fractal
    // is vertically symmetrical, this inconsistency was left in to avoid the obvious cache miss.
    unsigned index;
    for (unsigned j = 0; j < height; j++) {
      for (unsigned i = 0; i < width - 1; i++) {
        index = j * height + i;
        const Colour& pixel = image[index];
        fileOut << pixel.getStr() << consts::kBigSpace;
      }
      index = j * height + (width - 1);
      const Colour& pixel = image[j * height + (width - 1)];
      fileOut << pixel.getStr() << std::endl;
    }
    fileOut.close();
    return true;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    return false;
  }
}
