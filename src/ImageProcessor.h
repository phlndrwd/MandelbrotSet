#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <functional>
#include <string>
#include <vector>

#include "Colour.h"
#include "ColourMaps.h"

class ImageProcessor {
public:
  ImageProcessor();
  void toImage(std::vector<std::vector<Colour>>&, const std::vector<std::vector<unsigned>>&,
               const unsigned&, const unsigned&, const int&, const bool& invert = false);

private:
  ColourMaps colourMaps_;

  std::function<Colour(unsigned)> colourFunc_;

  unsigned calcIndex(double, const double&, const double&, const bool& invert);
};

#endif // IMAGEPROCESSOR_H
