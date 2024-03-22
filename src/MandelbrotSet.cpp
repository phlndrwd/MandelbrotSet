#include "MandelbrotSet.h"

#include <omp.h>

#include <algorithm>
#include <cmath>
#include <complex>

MandelbrotSet::MandelbrotSet(const unsigned& width, const unsigned& height, const unsigned& maxIter,
			     const double& xMin, const double& xMax, const double& yMin, const double& yMax,
			     const double& threshold, const int& colourMapOptIndex, const bool& invert, Image& image) :
    xAxis_(width, 0), yAxis_(height, 0), width_(width), data_(width * height, 0),
    imageProcessor_(width, height, 0, maxIter, colourMapOptIndex, invert), height_(height), maxIter_(maxIter),
    xMin_(xMin), xMax_(xMax), yMin_(yMin), yMax_(yMax), threshold_(threshold) {
  reset(image);  // Calculate default axes and create initial image
}

void MandelbrotSet::reset(Image& image) {
  double xInc = calcIncrement(xMin_, xMax_, width_);
  double yInc = calcIncrement(yMin_, yMax_, height_);
  const double& xMin = xMin_;
  const double& yMin = yMin_;
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
  iterate();
  imageProcessor_.toImage(image, data_);
}

void MandelbrotSet::calcAxes(const unsigned& xMinIdx, const unsigned& xMaxIdx,
                             const unsigned& yMinIdx, const unsigned& yMaxIdx) {
  double xMin = xAxis_[xMinIdx];
  double xMax = xAxis_[xMaxIdx];
  double yMin = yAxis_[yMinIdx];
  double yMax = yAxis_[yMaxIdx];

  double xInc = calcIncrement(xMin, xMax, width_);
  double yInc = calcIncrement(yMin, yMax, height_);

  unsigned n;
  std::generate(std::begin(xAxis_), std::end(xAxis_), [n = 0, &xInc, &xMin] () mutable {
      return (n++ * xInc) + xMin;
  });
  std::generate(std::begin(yAxis_), std::end(yAxis_), [n = 0, &yInc, &yMin] () mutable {
      return (n++ * yInc) + yMin;
  });
}

const double MandelbrotSet::calcIncrement(const double& min, const double& max, const unsigned& size) const {
  double inc = (max - min) / (double)(size - 1);
  return inc;
}

void MandelbrotSet::iterate() {
#pragma omp parallel for default(none) shared(maxIter_, threshold_, data_) schedule(static, 1)
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
      data_[index] = iter;
    }
  }
}
