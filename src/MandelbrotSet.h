/******************************************************************************
* MandelbrotSet                                                               *
*                                                                             *
* (C) Copyright 2024, Phil Underwood. All rights reserved.                    *
*                                                                             *
* This software is licensed under the terms of the 3-Clause BSD License       *
* which can be obtained from https://opensource.org/license/bsd-3-clause/.    *
******************************************************************************/

#ifndef MANDELBROTSET_H
#define MANDELBROTSET_H

#include <vector>

#include "ImageProcessor.h"

class MandelbrotSet {
public:
  MandelbrotSet(const unsigned&, const unsigned&, const unsigned&, const double&, const double&,
                const double&, const double&, const double&, const int&, const bool&, Image& image);

  void reset(Image& image);
  void run(const unsigned&, const unsigned&, const unsigned&, const unsigned&, Image& image);
  const std::vector<Colour>& getImageFile() const;

private:
  void calcAxes(const unsigned&, const unsigned&, const unsigned&, const unsigned&);
  const long double calcIncrement(const long double&, const long double&, const unsigned&) const;
  void iterate(unsigned&, unsigned&);

  std::vector<long double> xAxis_;
  std::vector<long double> yAxis_;

  const unsigned width_;
  const unsigned height_;

  std::vector<unsigned> data_;
  ImageProcessor imageProcessor_;

  const unsigned maxIter_;

  const long double xMin_;
  const long double xMax_;
  const long double yMin_;
  const long double yMax_;
  const double threshold_;
};

#endif // MANDELBROTSET_H
