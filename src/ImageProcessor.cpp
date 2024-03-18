#include "ImageProcessor.h"

#include <cmath>

ImageProcessor::ImageProcessor(const unsigned& width, const unsigned& height,
			       const unsigned& min, const unsigned& max,
			       const int& colourMapOptIndex, const bool& invert) :
    width_(width), height_(height), min_(min), max_(max), colourMapOptIndex_(colourMapOptIndex), invert_(invert) {
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

void ImageProcessor::toImage(Image& image, const std::vector<unsigned>& data) {
  for (unsigned j = 0; j < height_; j++) {
    for (unsigned i = 0; i < width_; i++) {
      unsigned index = j * height_ + i;
      const Colour& pixel = colourFunc_(calcIndex(data[index]));
      Color color(pixel.getR(), pixel.getG(), pixel.getB(), 255);  // Alpha is hard-coded opaque.
      ImageDrawPixel(&image, i, j, color);
    }
  }
}

unsigned ImageProcessor::calcIndex(double value) const {
  if (value < min_) {
    value = min_;
  } else if (value > max_) {
    value = max_;
  }
  if (invert_) {
    value = max_ - value;
  }
  double fracVal = value / (max_ - min_);
  return std::round(fracVal * (consts::kNumberOfColours - 1));
}
