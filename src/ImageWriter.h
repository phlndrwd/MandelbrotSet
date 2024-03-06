#ifndef IMAGEWRITER_H
#define IMAGEWRITER_H

#include <string>
#include <vector>

#include "Colour.h"

class ImageWriter {
public:
  ImageWriter();
  bool toPPM(const std::vector<Colour>&, const std::string&, const unsigned&, const unsigned&);
private:

};

#endif // IMAGEWRITER_H
