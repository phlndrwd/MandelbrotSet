/******************************************************************************
* MandelbrotSet                                                               *
*                                                                             *
* (C) Copyright 2024, Phil Underwood. All rights reserved.                    *
*                                                                             *
* This software is licensed under the terms of the 3-Clause BSD License       *
* which can be obtained from https://opensource.org/license/bsd-3-clause/.    *
******************************************************************************/

#include "ImageProcessor.h"

#include <cmath>

ImageProcessor::ImageProcessor(const unsigned& width, const unsigned& height,
			       const int& colourMapOptIndex, const bool& invert) :
    width_(width), height_(height), colourMapOptIndex_(colourMapOptIndex), invert_(invert), imageFile_(width * height) {
  switch (colourMapOptIndex_) {
    case enums::eBlackBody: {
        colourFunc_ = [&](unsigned index) { return colourMaps_.getBlackBody(index); };
        break;
    }
    case enums::eCoolWarm: {
        colourFunc_ = [&](unsigned index) { return colourMaps_.getCoolWarm(index); };
        break;
    }
    case enums::eGreyScale: {
        colourFunc_ = [&](unsigned index) { return colourMaps_.getGreyscale(index); };
        break;
    }
    case enums::ePlasma: {
        colourFunc_ = [&](unsigned index) { return colourMaps_.getPlasma(index); };
        break;
    }
    case enums::eTurbo: {
        colourFunc_ = [&](unsigned index) { return colourMaps_.getTurbo(index); };
        break;
    }
    case enums::eViridis: {
        colourFunc_ = [&](unsigned index) { return colourMaps_.getViridis(index); };
        break;
    }
    default: {
        colourFunc_ = [&](unsigned index) { return colourMaps_.getCoolWarm(index); };
        break;
    }
  }
}

void ImageProcessor::toImage(Image& image, const std::vector<unsigned>& data, const unsigned& min, const unsigned& max) {
  for (unsigned j = 0; j < height_; j++) {
    for (unsigned i = 0; i < width_; i++) {
      unsigned index = j * height_ + i;
      const Colour& pixel = colourFunc_(calcIndex(data[index], min, max));
      imageFile_[index] = pixel;
      Color color(pixel.getR(), pixel.getG(), pixel.getB(), consts::kColourDepth);  // Alpha is hard-coded opaque.
      ImageDrawPixel(&image, i, j, color);
    }
  }
}

unsigned ImageProcessor::calcIndex(double value, const unsigned& min, const unsigned& max) const {
  if (value < min) {
    value = min;
  } else if (value > max) {
    value = max;
  }
  if (invert_) {
    value = max - value;
  }
  double fracVal = (value - min) / (max - min);
  return std::round(fracVal * (consts::kColourMapSize - 1));
}

const std::vector<Colour>& ImageProcessor::getImageFile() const {
  return imageFile_;
}
