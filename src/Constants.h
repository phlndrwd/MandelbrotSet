#ifndef CONSTANTS_H
#define CONSTANTS_H
/******************************************************************************
* MandelbrotSet                                                               *
*                                                                             *
* (C) Copyright 2024, Phil Underwood. All rights reserved.                    *
*                                                                             *
* This software is licensed under the terms of the 3-Clause BSD License       *
* which can be obtained from https://opensource.org/license/bsd-3-clause/.    *
******************************************************************************/

#include <string>
#include <vector>

namespace enums {
  enum eColourMapOptions {
    eBlackBody,
    eCoolWarm,
    eGreyScale,
    ePlasma,
    eTurbo,
    eViridis
  };
}  // namespace enums

namespace consts {
  const std::vector<std::string> kColourMapOpts{
    "blackbody",
    "coolwarm",
    "greyscale",
    "plasma",
    "turbo",
    "viridis"
  };

  const char kSeparator = ',';

  const unsigned kColourDepth = 255;
  const unsigned kColourMapSize = 256;

  const unsigned kMaxColourSize = 3;

  const std::string kSpace = " ";
  const std::string kBigSpace = "  ";
  const std::string kInputPath = "./input/";
  const std::string kParamFile = "params.txt";
}  // namespace consts

#endif // CONSTANTS_H
