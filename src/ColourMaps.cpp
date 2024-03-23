/******************************************************************************
* MandelbrotSet                                                               *
*                                                                             *
* (C) Copyright 2024, Phil Underwood. All rights reserved.                    *
*                                                                             *
* This software is licensed under the terms of the 3-Clause BSD License       *
* which can be obtained from https://opensource.org/license/bsd-3-clause/.    *
******************************************************************************/

#include "ColourMaps.h"

#include <stdexcept>

ColourMaps::ColourMaps() {}

const Colour ColourMaps::getCoolWarm(const unsigned& index) {
  if (index >= consts::kColourMapSize) {
    throw std::runtime_error("Error in ColourMaps::getCoolWarm: Index out-of-bounds...");
  }
  return coolWarm_[index];
}

const Colour ColourMaps::getGreyscale(const unsigned& index) {
  if (index >= consts::kColourMapSize) {
    throw std::runtime_error("Error in ColourMaps::getGreyscale: Index out-of-bounds...");
  }
  return Colour(index, index, index);
}

const Colour ColourMaps::getBlackBody(const unsigned& index) {
  if (index >= consts::kColourMapSize) {
    throw std::runtime_error("Error in ColourMaps::getBlackBody: Index out-of-bounds...");
  }
  return blackBody_[index];
}

const Colour ColourMaps::getPlasma(const unsigned& index) {
  if (index >= consts::kColourMapSize) {
    throw std::runtime_error("Error in ColourMaps::getPlasma: Index out-of-bounds...");
  }
  return plasma_[index];
}

const Colour ColourMaps::getTurbo(const unsigned& index) {
  if (index >= consts::kColourMapSize) {
    throw std::runtime_error("Error in ColourMaps::getTurbo: Index out-of-bounds...");
  }
  return turbo_[index];
}

const Colour ColourMaps::getViridis(const unsigned& index) {
  if (index >= consts::kColourMapSize) {
    throw std::runtime_error("Error in ColourMaps::getViridis: Index out-of-bounds...");
  }
  return viridis_[index];
}
