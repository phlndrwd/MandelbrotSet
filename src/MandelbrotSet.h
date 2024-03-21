#ifndef MANDELBROTSET_H
#define MANDELBROTSET_H

#include <vector>

#include "ImageProcessor.h"

class MandelbrotSet {
public:
  MandelbrotSet(const unsigned&, const unsigned&, const unsigned&, const double&, const double&,
                const double&, const double&, const double&, const int&, const bool&);

  void run(const unsigned&, const unsigned&, const unsigned&, const unsigned&, Image& image);

private:
  void calcAxes(const unsigned&, const unsigned&, const unsigned&, const unsigned&);
  const double calcIncrement(const double&, const double&, const unsigned&) const;
  void iterate();

  std::vector<double> xAxis_;
  std::vector<double> yAxis_;

  const unsigned width_;
  const unsigned height_;

  std::vector<unsigned> data_;
  ImageProcessor imageProcessor_;

  const unsigned maxIter_;

  const double xMin_;
  const double xMax_;
  const double yMin_;
  const double yMax_;
  const double threshold_;
};

#endif // MANDELBROTSET_H
