#ifndef MANDELBROTSET_H
#define MANDELBROTSET_H

#include <vector>

class MandelbrotSet {
public:
  MandelbrotSet(const unsigned&, const unsigned&, const unsigned&, const double&,
                const double&, const double&, const double&, const double&);

  void run(const unsigned&, const unsigned&, const unsigned&, const unsigned&, std::vector<unsigned>&);

private:
  void calcAxes(const unsigned&, const unsigned&, const unsigned&, const unsigned&);
  const double calcIncrement(const double&, const double&, const unsigned&) const;
  void iterate(std::vector<unsigned>&) const;

  std::vector<double> xAxis_;
  std::vector<double> yAxis_;

  const unsigned width_;
  const unsigned height_;
  const unsigned maxIter_;

  const double xMin_;
  const double xMax_;
  const double yMin_;
  const double yMax_;
  const double threshold_;
};

#endif // MANDELBROTSET_H
