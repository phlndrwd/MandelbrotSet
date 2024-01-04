#include <omp.h>

#include <any>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "FileReader.h"
#include "ImageProcessor.h"
#include "ImageWriter.h"
#include "MandelbrotSet.h"
#include "Utils.h"

int main() {
  double startTime = omp_get_wtime();

  std::cout << "Reading parameters..." << std::endl;
  std::map<std::string, std::any> values;
  FileReader fileReader;
  if (fileReader.readParams(values)) {
    unsigned maxIter = std::any_cast<unsigned>(values["maxIter"]);
    unsigned width = std::any_cast<unsigned>(values["width"]);
    unsigned height = std::any_cast<unsigned>(values["height"]);
    double xMin = std::any_cast<double>(values["xMin"]);
    double xMax = std::any_cast<double>(values["xMax"]);
    double yMin = std::any_cast<double>(values["yMin"]);
    double yMax = std::any_cast<double>(values["yMax"]);
    std::string colourMapOption = utils::strTolower(std::any_cast<std::string>(values["colourMapOption"]));
    bool colourInvert = std::any_cast<bool>(values["colourInvert"]);
    std::string imagePath = std::any_cast<std::string>(values["imagePath"]);

    int colourMapOptIndex = utils::findPosInVector(consts::kColourMapOpts, colourMapOption);
    if (colourMapOptIndex == -1) {
      std::cout << "Error: Colour map option \"" << colourMapOption << "\" is not valid. Using default..." << std::endl;
    }
    std::cout << "Initialising variables..." << std::endl;
    std::vector<std::vector<unsigned>> data(width, std::vector<unsigned>(height, 0));
    std::vector<std::vector<Colour>> image(width, std::vector<Colour>(height));

    std::cout << "Calculating Mandelbrot set with width = " << width << ", height = " << height
              << ", and maxIter = " << maxIter << "..." << std::endl;
    MandelbrotSet mandelbrotSet(width, height, xMin, xMax, yMin, yMax);
    mandelbrotSet.iterate(maxIter, data);

    std::cout << "Creating image..." << std::endl;
    ImageProcessor imageProcessor;
    imageProcessor.toImage(image, data, 0, maxIter, colourMapOptIndex, colourInvert);

    std::cout << "Writing " << imagePath << " to disk..." << std::endl;
    ImageWriter imageWriter;
    if (imageWriter.toPPM(image, imagePath) == false) {
      std::cout << "No image file produced." << std::endl;
    }
    std::cout << "Time taken = " << omp_get_wtime() - startTime << "seconds." << std::endl;
  }
}
