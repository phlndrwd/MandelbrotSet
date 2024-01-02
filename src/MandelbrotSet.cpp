#include "MandelbrotSet.h"

#include <algorithm>
//#include <cmath>
//#include <complex>

struct complex{
  double real;
  double imag;
};

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

void MandelbrotSet::iterate(const unsigned& maxIter, std::vector<std::vector<unsigned>>& domain) {
  complex c;
  complex z;
  double x;
  double y;

  for (unsigned i = 0; i < width_; i++) {
    x = xAxis_[i];
    for (unsigned j = 0; j < height_; j++) {
      y = yAxis_[j];
      c.real = x;
      c.imag = y;
      z = c;
      unsigned iter = 0;
      for (iter = 0; iter < maxIter; iter++) {
        double zReal = (z.real * z.real) - (z.imag * z.imag) + c.real;
        z.imag = z.real * z.imag * 2 + c.imag;
        z.real = zReal;
        double val = (z.real * z.real + z.imag * z.imag);
        if (val > 4.0e0) {
          break;
        }
      }
      domain[i][j] = iter;
    }
  }
}

const double MandelbrotSet::calcIncrement(const double& max, const double& min, const unsigned& size) {
  double inc = (max - min) / (double)(size - 1);
  return inc;
}
