/******************************************************************************
* MandelbrotSet                                                               *
*                                                                             *
* (C) Copyright 2024, Phil Underwood. All rights reserved.                    *
*                                                                             *
* This software is licensed under the terms of the 3-Clause BSD License       *
* which can be obtained from https://opensource.org/license/bsd-3-clause/.    *
******************************************************************************/

#include <any>
#include <iostream>
#include <string>
#include <vector>

#include "raylib-cpp.hpp"

#include "FileReader.h"
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

void leftMouseButtonPress(raylib::Vector2& initZoom, raylib::Vector2& startZoom, bool& mouseDown) {
  initZoom = GetMousePosition();
  startZoom = initZoom;
  mouseDown = true;
}

void leftMouseButtonDown(const raylib::Vector2& initZoom, raylib::Vector2& startZoom, int& zoomSize, bool& mouseDown) {
  startZoom = initZoom;
  raylib::Vector2 currentZoom = GetMousePosition();
  int zoomWidth = currentZoom.x - initZoom.x;
  bool setStart = false;
  if (zoomWidth < 0) {
    zoomWidth = initZoom.x - currentZoom.x;
    setStart = true;
  }
  int zoomHeight = currentZoom.y - initZoom.y;
  if (zoomHeight < 0) {
    zoomHeight = initZoom.y - currentZoom.y;
    setStart = true;
  }
  zoomSize = std::min(zoomWidth, zoomHeight);
  if (setStart == true) {
    startZoom.x = initZoom.x - zoomSize;
    startZoom.y = initZoom.y - zoomSize;
  }
}

void leftMouseButtonLift(MandelbrotSet& mandelbrotSet, Image& image, raylib::Texture2D& texture,
                         const raylib::Vector2& startZoom, const int& zoomSize, bool& mouseDown) {
  mouseDown = false;
  mandelbrotSet.run(startZoom.x, zoomSize, startZoom.y, zoomSize, image);
  texture.Unload();  // Requires unload before load to prevent serious memory leak
  texture.Load(image);
}

void rightMouseButtonPress(MandelbrotSet& mandelbrotSet, Image& image, raylib::Texture2D& texture) {
  mandelbrotSet.reset(image);
  texture.Unload();  // Requires unload before load to prevent serious memory leak
  texture.Load(image);
}

void writeToFile(MandelbrotSet& mandelbrotSet, ImageWriter& imageWriter, const std::string& imagePath,
                 const unsigned& width, const unsigned& height) {
  std::cout << "Writing " << imagePath << " to disk..." << std::endl;
  if (imageWriter.toPPM(mandelbrotSet.getImageFile(), imagePath, width, height) == false) {
    std::cout << "No image file produced." << std::endl;
  }
  std::cout << "Writing complete." << std::endl;
}

void drawZoomBox(const MandelbrotSet& mandelbrotSet, const raylib::Vector2& startZoom, const int& zoomSize,
                 const unsigned& width, const unsigned& height) {
  const std::vector<Colour>& imageFile = mandelbrotSet.getImageFile();
  int startX = startZoom.x;
  int startY = startZoom.y;
  int endX = startZoom.x + zoomSize;
  int endY = startZoom.y + zoomSize;

  for (int i = startX; i < endX; ++i) {
    unsigned index1 = startY * height + i;
    unsigned index2 = endY * height + i;
    Colour colour1 = imageFile[index1];
    Colour colour2 = imageFile[index2];
    colour1.invert();
    colour2.invert();
    Color color1(colour1.getR(), colour1.getG(), colour1.getB(), consts::kColourDepth);  // Alpha is hard-coded opaque
    Color color2(colour2.getR(), colour2.getG(), colour2.getB(), consts::kColourDepth);  // Alpha is hard-coded opaque
    DrawPixel(i, startY, color1);
    DrawPixel(i, endY, color2);
  }
  for (int j = startY; j < endY; ++j) {
    unsigned index1 = j * height + startX;
    unsigned index2 = j * height + endX;
    Colour colour1 = imageFile[index1];
    Colour colour2 = imageFile[index2];
    colour1.invert();
    colour2.invert();
    Color color1(colour1.getR(), colour1.getG(), colour1.getB(), consts::kColourDepth);  // Alpha is hard-coded opaque
    Color color2(colour2.getR(), colour2.getG(), colour2.getB(), consts::kColourDepth);  // Alpha is hard-coded opaque
    DrawPixel(startX, j, color1);
    DrawPixel(endX, j, color2);
  }
}

void showWindow(MandelbrotSet& mandelbrotSet, ImageWriter& imageWriter, Image& image,
                const std::string& imagePath, const unsigned& width, const unsigned& height) {
  raylib::Window window(width, height, "MandelbrotSet");

  raylib::Texture2D texture(image);
  raylib::Vector2 initZoom(0, 0);
  raylib::Vector2 startZoom(0, 0);

  int zoomSize = 0;
  bool mouseDown = false;

  SetTargetFPS(60);
  while (window.ShouldClose()== false) {
    // Respond to and process mouse events
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      leftMouseButtonPress(initZoom, startZoom, mouseDown);
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      leftMouseButtonDown(initZoom, startZoom, zoomSize, mouseDown);
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
      leftMouseButtonLift(mandelbrotSet, image, texture, startZoom, zoomSize,mouseDown);
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
      rightMouseButtonPress(mandelbrotSet, image, texture);
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) {
      writeToFile(mandelbrotSet, imageWriter, imagePath, width, height);
    }
    // Draw graphics
    window.BeginDrawing();
    texture.Draw(0, 0, WHITE);
    if (mouseDown == true) {
      drawZoomBox(mandelbrotSet, startZoom, zoomSize, width, height);
    }
    window.EndDrawing();
  }
  // Gracefully exit
  texture.Unload();
  window.Close();
}

int main() {
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
    Image image = GenImageColor(width, height, BLACK);
    MandelbrotSet mandelbrotSet(width, height, maxIter, xMin, xMax, yMin, yMax,
                                threshold, colourMapOptIndex, colourInvert, image);
    ImageWriter imageWriter;
    showWindow(mandelbrotSet, imageWriter, image, imagePath, width, height);
  } else {
    std::cout << "Error: Input file reading failed." << std::endl;
  }
  return 0;
}
