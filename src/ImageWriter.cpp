#include "ImageWriter.h"

#include <fstream>
#include <iostream>

#include "Constants.h"

ImageWriter::ImageWriter() {}


bool ImageWriter::toPPM(const std::vector<std::vector<Colour>>& image, const std::string& filePath) {
  unsigned width = image.size();
  unsigned height = image[0].size();
  try {
    std::ofstream fileOut(filePath);
    fileOut << "P3" << std::endl;
    fileOut << width << " " << height << std::endl;
    fileOut << "255" << std::endl;

    for (unsigned i = 0; i < width; i++) {
      for (unsigned j = 0; j < height - 1; j++) {
          const Colour& pixel = image[i][j];
          fileOut << pixel.getStr() << consts::kBigSpace;
      }
      const Colour& pixel = image[i][height - 1];
      fileOut << pixel.getStr() << std::endl;
    }
    fileOut.close();
    return true;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    return false;
  }
}
