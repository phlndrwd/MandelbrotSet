#ifndef COLOURMAP_H
#define COLOURMAP_H

#include <string>
#include <vector>

#include "Colour.h"

class ColourMap {
public:
  ColourMap();
  void toImage(std::vector<std::vector<Colour>>&, const std::vector<std::vector<unsigned>>&,
               const unsigned&, const unsigned&, const std::string, const bool& invert = false);

private:
  Colour toGreyScale(double, const double&, const double&, const bool& invert);
  Colour toPlasma(double, const double&, const double&, const bool& invert);
  Colour toLava(double, const double&, const double&, const bool& invert);
};

#endif // COLOURMAP_H
