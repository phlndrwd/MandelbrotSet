#include "ColourMaps.h"

#include <stdexcept>

ColourMaps::ColourMaps() {}

Colour ColourMaps::getCoolWarm(const unsigned& index) {
  if (index >= consts::kNumberOfColours) {
    throw std::runtime_error("Error in ColourMaps::getCoolWarm: Index out-of-bounds...");
  }
  return coolWarm_[index];
}

Colour ColourMaps::getGreyscale(const unsigned& index) {
  if (index >= consts::kNumberOfColours) {
    throw std::runtime_error("Error in ColourMaps::getGreyscale: Index out-of-bounds...");
  }
  return Colour(index, index, index);
}

Colour ColourMaps::getBlackBody(const unsigned& index) {
  if (index >= consts::kNumberOfColours) {
    throw std::runtime_error("Error in ColourMaps::getBlackBody: Index out-of-bounds...");
  }
  return blackBody_[index];
}

Colour ColourMaps::getPlasma(const unsigned& index) {
  if (index >= consts::kNumberOfColours) {
    throw std::runtime_error("Error in ColourMaps::getPlasma: Index out-of-bounds...");
  }
  return plasma_[index];
}

Colour ColourMaps::getTurbo(const unsigned& index) {
  if (index >= consts::kNumberOfColours) {
    throw std::runtime_error("Error in ColourMaps::getTurbo: Index out-of-bounds...");
  }
  return turbo_[index];
}

Colour ColourMaps::getViridis(const unsigned& index) {
  if (index >= consts::kNumberOfColours) {
    throw std::runtime_error("Error in ColourMaps::getViridis: Index out-of-bounds...");
  }
  return viridis_[index];
}
