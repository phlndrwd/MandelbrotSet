#include "MandelbrotSet.h"

#include <omp.h>

#include <algorithm>
#include <cmath>
#include <complex>

MandelbrotSet::MandelbrotSet(const unsigned& width, const unsigned& height,
                             const unsigned& maxIter, const double& threshold) :
    xAxis_(width, 0), yAxis_(height, 0), width_(width), height_(height), maxIter_(maxIter), threshold_(threshold) {}

void MandelbrotSet::run(const double& xMin, const double& xMax, const double& yMin, const double& yMax,
                        std::vector<unsigned>& data) {
  calcAxes(xMin, xMax, yMin, yMax);
  iterate(data);
}

void MandelbrotSet::calcAxes(const double& xMin, const double& xMax, const double& yMin, const double& yMax) {
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

const double MandelbrotSet::calcIncrement(const double& max, const double& min, const unsigned& size) const {
  double inc = (max - min) / (double)(size - 1);
  return inc;
}

void MandelbrotSet::iterate(std::vector<unsigned>& data) const {
#pragma omp parallel for default(none) shared(maxIter_, threshold_, data) schedule(static, 1)
  for (unsigned j = 0; j < height_; j++) {
    double y = yAxis_[j];
    for (unsigned i = 0; i < width_; i++) {
      double x = xAxis_[i];
      std::complex<double> c(x, y);
      std::complex<double> z = 0;
      unsigned iter = 0;
      for (iter = 0; iter < maxIter_; iter++) {
        z = z * z + c;
        if (std::abs(z) > threshold_) {
          break;
        }
      }
      unsigned index = j * height_ + i;
      data[index] = iter;
    }
  }
}
