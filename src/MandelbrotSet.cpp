#include "MandelbrotSet.h"

#include <algorithm>
#include <cmath>
#include <complex>

MandelbrotSet::MandelbrotSet(const unsigned& width, const unsigned& height, const double& xMin,
                             const double& xMax, const double& yMin, const double& yMax) :
                                 xAxis_(width, 0), yAxis_(height, 0),
                                 width_(width), height_(height) {
  double xInc = calcIncrement(xMax, xMin, width_);
  double yInc = calcIncrement(yMax, yMin, height_);
  unsigned n;
  std::generate(std::begin(xAxis_), std::end(xAxis_), [n = 0, &xInc, &xMin] () mutable {
    return (n++ * xInc) + xMin;
  });
  std::generate(std::begin(yAxis_), std::end(yAxis_), [n = 0, &yInc, &yMin] () mutable {
    return (n++ * yInc) + yMin;
  });
}

void MandelbrotSet::iterate(const unsigned maxIter, const double threshold, std::vector<std::vector<unsigned>>& data) {
  for (unsigned i = 0; i < width_; i++) {
    double x = xAxis_[i];
    for (unsigned j = 0; j < height_; j++) {
      double y = yAxis_[j];
      std::complex<double> c(x, y);
      std::complex<double> z = 0;
      unsigned iter = 0;
      for (iter = 0; iter < maxIter; iter++) {
        z = z * z + c;
        if (std::abs(z) > threshold) {
          break;
        }
      }
      data[i][j] = iter;
    }
  }
}

const double MandelbrotSet::calcIncrement(const double& max, const double& min, const unsigned& size) {
  double inc = (max - min) / (double)(size - 1);
  return inc;
}
