/******************************************************************************
* MandelbrotSet                                                               *
*                                                                             *
* (C) Copyright 2024, Phil Underwood. All rights reserved.                    *
*                                                                             *
* This software is licensed under the terms of the 3-Clause BSD License       *
* which can be obtained from https://opensource.org/license/bsd-3-clause/.    *
******************************************************************************/

#include "MandelbrotSet.h"

#include <omp.h>

#include <algorithm>
#include <cmath>
#include <complex>

MandelbrotSet::MandelbrotSet(const unsigned& width, const unsigned& height, const unsigned& maxIter,
			     const double& xMin, const double& xMax, const double& yMin, const double& yMax,
			     const double& threshold, const int& colourMapOptIndex, const bool& invert, Image& image) :
    xAxis_(width, 0), yAxis_(height, 0), width_(width), data_(width * height, 0),
    imageProcessor_(width, height, colourMapOptIndex, invert), height_(height), maxIter_(maxIter),
    xMin_(xMin), xMax_(xMax), yMin_(yMin), yMax_(yMax), threshold_(threshold) {
  reset(image);  // Calculate default axes and create initial image
}

void MandelbrotSet::reset(Image& image) {
  long double xInc = calcIncrement(xMin_, xMax_, width_);
  long double yInc = calcIncrement(yMin_, yMax_, height_);
  const long double& xMin = xMin_;
  const long double& yMin = yMin_;
  unsigned n;
  std::generate(std::begin(xAxis_), std::end(xAxis_), [n = 0, &xInc, &xMin] () mutable {
    return (n++ * xInc) + xMin;
  });
  std::generate(std::begin(yAxis_), std::end(yAxis_), [n = 0, &yInc, &yMin] () mutable {
    return (n++ * yInc) + yMin;
  });
  run(0, 999, 0, 999, image);
}

void MandelbrotSet::run(const unsigned& xMinZoomIdx, const unsigned& xZoomWidth,
                        const unsigned& yMinZoomIdx, const unsigned& yZoomHeight, Image& image) {

  unsigned xMaxZoomIdx = xMinZoomIdx + xZoomWidth;
  unsigned yMaxZoomIdx = yMinZoomIdx + yZoomHeight;
  calcAxes(xMinZoomIdx, xMaxZoomIdx, yMinZoomIdx, yMaxZoomIdx);
  unsigned min =  std::numeric_limits<unsigned>::max();
  unsigned max = 0;
  iterate(min, max);
  imageProcessor_.toImage(image, data_, min, max);
}

void MandelbrotSet::calcAxes(const unsigned& xMinIdx, const unsigned& xMaxIdx,
                             const unsigned& yMinIdx, const unsigned& yMaxIdx) {
  long double xMin = xAxis_[xMinIdx];
  long double xMax = xAxis_[xMaxIdx];
  long double yMin = yAxis_[yMinIdx];
  long double yMax = yAxis_[yMaxIdx];

  long double xInc = calcIncrement(xMin, xMax, width_);
  long double yInc = calcIncrement(yMin, yMax, height_);

  unsigned n;
  std::generate(std::begin(xAxis_), std::end(xAxis_), [n = 0, &xInc, &xMin] () mutable {
      return (n++ * xInc) + xMin;
  });
  std::generate(std::begin(yAxis_), std::end(yAxis_), [n = 0, &yInc, &yMin] () mutable {
      return (n++ * yInc) + yMin;
  });
}

const long double MandelbrotSet::calcIncrement(const long double& min, const long double& max, const unsigned& size) const {
  long double inc = (max - min) / (long double)(size - 1);
  return inc;
}

void MandelbrotSet::iterate(unsigned& min, unsigned& max) {
#pragma omp parallel for default(none) shared(maxIter_, min, max, threshold_, data_) schedule(static, 1)
  for (unsigned j = 0; j < height_; j++) {
    long double y = yAxis_[j];
    for (unsigned i = 0; i < width_; i++) {
      long double x = xAxis_[i];
      std::complex<long double> c(x, y);
      std::complex<long double> z = 0;
      unsigned iter = 0;
      for (iter = 0; iter < maxIter_; iter++) {
        z = z * z + c;
        if (std::abs(z) > threshold_) {
          break;
        }
      }
      unsigned index = j * height_ + i;
      data_[index] = iter;
      #pragma omp critical
      {
        if (iter < min) min = iter;
        if (iter > max) max = iter;
      }
    }
  }
}

const std::vector<Colour>& MandelbrotSet::getImageFile() const {
  return imageProcessor_.getImageFile();
}
