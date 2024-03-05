#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <functional>
#include <vector>

#include "Colour.h"
#include "ColourMaps.h"

class ImageProcessor {
public:
  ImageProcessor(const unsigned&, const unsigned&);
  void toImage(std::vector<std::vector<Colour>>&, const std::vector<std::vector<unsigned>>&,
               const int&, const bool& invert = false);

private:
  ColourMaps colourMaps_;

  std::function<Colour(unsigned)> colourFunc_;

  unsigned calcIndex(double, const double&, const double&, const bool& invert);

  const unsigned min_;
  const unsigned max_;
};

#endif // IMAGEPROCESSOR_H
