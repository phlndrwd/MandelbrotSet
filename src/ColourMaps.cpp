#include "ColourMaps.h"

ColourMaps::ColourMaps() {}

Colour ColourMaps::getTurbo(const unsigned& index) {
  if (index >= consts::kNumberOfColours) {
    throw std::runtime_error("Error in ColourMaps::getTurbo: Index out-of-bounds...");
  }
  return turbo_[index];
}
