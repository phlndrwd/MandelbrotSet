#ifndef MANDELBROTSET_H
#define MANDELBROTSET_H

#include <vector>

class MandelbrotSet {
public:
  MandelbrotSet(const unsigned&, const unsigned&, const double&,
                const double&, const double&, const double&);
  void iterate(const unsigned&, std::vector<std::vector<unsigned>>&);

private:
  const double calcIncrement(const double&, const double&, const unsigned&);

  std::vector<double> xAxis_;
  std::vector<double> yAxis_;

  const unsigned width_;
  const unsigned height_;
};

#endif // MANDELBROTSET_H
