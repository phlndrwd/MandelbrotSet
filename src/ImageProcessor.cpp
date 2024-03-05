#include "ImageProcessor.h"

#include <cmath>

ImageProcessor::ImageProcessor(const unsigned& min, const unsigned& max) : min_(min), max_(max) {}

void ImageProcessor::toImage(std::vector<std::vector<Colour>>& image,
                        const std::vector<std::vector<unsigned>>& data,
                        const int& colourMapOptIndex,
                        const bool& invert) {
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
  unsigned width = data.size();
  unsigned height = data[0].size();

  for (unsigned i = 0; i < width; i++) {
    for (unsigned j = 0; j < height; j++) {
      image[i][j] = colourFunc_(calcIndex(data[i][j], min_, max_, invert));
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
