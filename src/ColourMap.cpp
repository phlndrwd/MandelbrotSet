#include "ColourMap.h"

#include <cmath>

ColourMap::ColourMap() {}

void ColourMap::toImage(std::vector<std::vector<Colour>>& image,
                        const std::vector<std::vector<unsigned>>& data,
                        const unsigned& min, const unsigned& max,
                        const std::string colourMap,
                        const bool& invert) {
  unsigned width = data.size();
  unsigned height = data[0].size();

  for (unsigned i = 0; i < width; i++) {
    for (unsigned j = 0; j < height; j++) {
      image[i][j] = toLava(data[i][j], min, max, invert);
    }
  }
}

Colour ColourMap::toGreyScale(double value, const double& min,
                              const double& max, const bool& invert) {
  if (value < min) {
    value = min;
  } else if (value > max) {
    value = max;
  }
  if (invert) {
    value = max - value;
  }
  double range = max - min;
  unsigned valueCol = (unsigned)std::round(255 * (value / range));
  Colour c(valueCol);

  return c;
}

Colour ColourMap::toPlasma(double value, const double& min,
                           const double& max, const bool& invert) {
  if (value < min) {
    value = min;
  } else if (value > max) {
    value = max;
  }
  if (invert) {
    value = max - value;
  }
  double range = max - min;
  double multiplier = 1020 / range;
  double valueCol = std::round(value * multiplier);

  Colour c;
  if ((valueCol >= 0) && (valueCol < 255)) {
    c.set(255 - valueCol, 255, 255);
  } else if ((valueCol >= 255) && (valueCol < 510)) {
    valueCol -= 255;
    c.set( 0, 255 - valueCol, 255);
  } else if ((valueCol >= 510) && (valueCol < 765)) {
    valueCol -= 510;
    c.set(valueCol, 0, 255 );
  } else if ((valueCol >= 765) && (valueCol < 1020)) {
    valueCol -= 765;
    c.set(255, 0, 255 - valueCol );
  } else {
    c.set(255, 0, 0);
  }
  return c;
}

Colour ColourMap::toLava(double value, const double& min,
                         const double& max, const bool& invert) {
  if (value < min) {
    value = min;
  } else if (value > max) {
    value = max;
  }
  if (invert) {
    value = max - value;
  }
  double range = max - min;
  double multiplier = 765 / range;
  double valueCol = std::round(value * multiplier);

  Colour c;
  if ((valueCol >= 0) && (valueCol < 255)) {
    c.set(valueCol, 0, 0);
  } else if ((valueCol >= 255) && (valueCol < 510)) {
      valueCol -= 255;
    c.set(255, valueCol, 0);
  } else if ((valueCol >= 510) && (valueCol < 765)) {
      valueCol -= 510;
    c.set(255, 255, valueCol);
  } else {
    c.set(255, 255, 255);
  }
  return c;
}
