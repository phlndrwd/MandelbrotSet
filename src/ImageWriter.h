/******************************************************************************
* MandelbrotSet                                                               *
*                                                                             *
* (C) Copyright 2024, Phil Underwood. All rights reserved.                    *
*                                                                             *
* This software is licensed under the terms of the 3-Clause BSD License       *
* which can be obtained from https://opensource.org/license/bsd-3-clause/.    *
******************************************************************************/

#ifndef IMAGEWRITER_H
#define IMAGEWRITER_H

#include <string>
#include <vector>

#include "Colour.h"

class ImageWriter {
public:
  ImageWriter();
  bool toPPM(const std::vector<Colour>&, const std::string&, const unsigned&, const unsigned&);
private:

};

#endif // IMAGEWRITER_H
