#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <functional>
#include <vector>

#include <raylib.h>

#include "Colour.h"
#include "ColourMaps.h"

class ImageProcessor {
public:
  ImageProcessor(const unsigned&, const unsigned&, const unsigned&, const unsigned&,
                 const int& colourMapOptIndex, const bool& invert);
  void toImage(Image&, const std::vector<unsigned>&);

private:
  unsigned calcIndex(double) const;
  std::function<Colour(unsigned)> colourFunc_;

  ColourMaps colourMaps_;

  const unsigned width_;
  const unsigned height_;
  const unsigned min_;
  const unsigned max_;
  const int colourMapOptIndex_;
  const bool invert_;
};

#endif // IMAGEPROCESSOR_H
