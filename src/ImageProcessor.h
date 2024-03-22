#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <functional>
#include <vector>

#include <raylib.h>

#include "Colour.h"
#include "ColourMaps.h"

class ImageProcessor {
public:
  ImageProcessor(const unsigned&, const unsigned&, const int&, const bool&);
  void toImage(Image&, const std::vector<unsigned>&, const unsigned&, const unsigned&);

  const std::vector<Colour>& getImageFile() const;

private:
  unsigned calcIndex(double, const unsigned&, const unsigned&) const;
  std::function<Colour(unsigned)> colourFunc_;

  ColourMaps colourMaps_;

  std::vector<Colour> imageFile_;

  const unsigned width_;
  const unsigned height_;
  const int colourMapOptIndex_;
  const bool invert_;
};

#endif // IMAGEPROCESSOR_H
