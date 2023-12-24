#include "ImageProcessor.h"

#include <cmath>

ImageProcessor::ImageProcessor() {}

void ImageProcessor::toImage(std::vector<std::vector<Colour>>& image,
                        const std::vector<std::vector<unsigned>>& data,
                        const unsigned& min, const unsigned& max,
                        const std::string colourMapOption,
                        const bool& invert) {

  colourFunc_ = [&](unsigned index) { return colourMaps_.getCoolWarm(index); };

  unsigned width = data.size();
  unsigned height = data[0].size();

  for (unsigned i = 0; i < width; i++) {
    for (unsigned j = 0; j < height; j++) {
      image[i][j] = colourFunc_(calcIndex(data[i][j], min, max, invert));
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
