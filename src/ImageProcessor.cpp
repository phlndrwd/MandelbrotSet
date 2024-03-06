#include "ImageProcessor.h"

#include <cmath>

ImageProcessor::ImageProcessor(const unsigned& width, const unsigned& height,
                               const unsigned& min, const unsigned& max) :
    width_(width), height_(height), min_(min), max_(max) {}

void ImageProcessor::toImage(std::vector<Colour>& image, const std::vector<unsigned>& data,
                             const int& colourMapOptIndex, const bool& invert) {
  switch (colourMapOptIndex) {
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

  for (unsigned j = 0; j < height_; j++) {
    for (unsigned i = 0; i < width_; i++) {
      unsigned index = j * height_ + i;
      image[index] = colourFunc_(calcIndex(data[index], min_, max_, invert));
    }
  }
}

unsigned ImageProcessor::calcIndex(double value, const double& min,
                                   const double& max, const bool& invert) {
  if (value < min) {
    value = min;
  } else if (value > max) {
    value = max;
  }
  if (invert) {
    value = max - value;
  }
  double fracVal = value / (max - min);
  return std::round(fracVal * (consts::kNumberOfColours - 1));
}
