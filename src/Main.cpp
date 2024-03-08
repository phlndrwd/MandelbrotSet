#include <omp.h>

#include <any>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "raylib.h"

#include "FileReader.h"
#include "ImageProcessor.h"
#include "ImageWriter.h"
#include "MandelbrotSet.h"

namespace {
int findPosInVector(std::vector<std::string> vector, std::string searchTerm) {
  int pos = -1;
  typename std::vector<std::string>::iterator it = std::find(vector.begin(), vector.end(), searchTerm);
  if (it != vector.end()) {
    return std::distance(vector.begin(), it);
  }
  return pos;
}
}

void drawFractal(const unsigned& width, const unsigned& height, std::vector<Colour>& image) {
  InitWindow(width, height, "Raylib Test");

  Image fracImage = GenImageColor(width, height, BLACK);
  for (unsigned j = 0; j < height; j++) {
    for (unsigned i = 0; i < width; i++) {
      const Colour& pixel = image[j * height + i];
      Color rayCol(pixel.getR(), pixel.getG(), pixel.getB(), 1);
      ImageDrawPixel(&fracImage, i, j, rayCol);
      //DrawRectangle(i, j, 1, 1, rayCol);
    }
  }
  Texture2D fracTexture = LoadTextureFromImage(fracImage);  // Image converted and uploaded to GPU memory (VRAM)
  UnloadImage(fracImage);  // Converted image can be unloaded from RAM
  SetTargetFPS(60);
  while (WindowShouldClose() == false) {
    BeginDrawing();
      DrawTexture(fracTexture, 0, 0, WHITE);
    EndDrawing();
  }
}

int main() {
  double startTime = omp_get_wtime();
  std::cout << "Reading parameters..." << std::endl;
  std::map<std::string, std::any> values;
  FileReader fileReader;
  if (fileReader.readParams(values)) {
    unsigned width = std::any_cast<unsigned>(values["width"]);
    unsigned height = std::any_cast<unsigned>(values["height"]);
    double xMin = std::any_cast<double>(values["xMin"]);
    double xMax = std::any_cast<double>(values["xMax"]);
    double yMin = std::any_cast<double>(values["yMin"]);
    double yMax = std::any_cast<double>(values["yMax"]);
    unsigned maxIter = std::any_cast<unsigned>(values["maxIter"]);
    double threshold = std::any_cast<double>(values["threshold"]);
    std::string colourMapOption = std::any_cast<std::string>(values["colourMapOption"]);
    bool colourInvert = std::any_cast<bool>(values["colourInvert"]);
    std::string imagePath = std::any_cast<std::string>(values["imagePath"]);
    int colourMapOptIndex = findPosInVector(consts::kColourMapOpts, colourMapOption);
    if (colourMapOptIndex == -1) {
      std::cout << "Error: Colour map option \"" << colourMapOption << "\" is not valid. Using default..." << std::endl;
    }

    std::cout << "Initialising variables..." << std::endl;
    std::vector<unsigned> data(width * height, 0);
    std::vector<Colour> image(width * height);

    std::cout << "Calculating Mandelbrot set with width = " << width << ", height = " << height
              << ", maxIter = " << maxIter << ", and threshold = " << threshold << "..." << std::endl;
    MandelbrotSet mandelbrotSet(width, height, maxIter, threshold);
    ImageProcessor imageProcessor(width, height, 0, maxIter, colourMapOptIndex, colourInvert);

    mandelbrotSet.run(xMin, xMax, yMin, yMax, data);
    imageProcessor.toImage(image, data);

    drawFractal(width, height, image);

    ImageWriter imageWriter;
    std::cout << "Writing " << imagePath << " to disk..." << std::endl;
    if (imageWriter.toPPM(image, imagePath, width, height) == false) {
      std::cout << "No image file produced." << std::endl;
    }
    std::cout << "Time taken = " << omp_get_wtime() - startTime << "seconds." << std::endl;

  }
  return 0;
}
