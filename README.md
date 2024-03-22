&copy; Copyright 2024 Phil Underwood 

# MandelbrotSet

## Description

MandelbrotSet is a simple program, written in C++ that graphically renders the famous Mandelbrot set fractal. Read the [Wikipedia page]((https://en.wikipedia.org/wiki/Mandelbrot_set) for more information on the mathematical concepts and algorithm behind it. The code makes use of [OpenMP](https://www.openmp.org/) for shared-memory parallelisation. The reason being that in its basic form the Mandelbrot algorithm is a perfectly parallelisable problem. The calculation of any given pixel value is independent from any other. 

The program graphics are provided by the [raylib](https://www.raylib.com/) library with its C++ wrapper [raylib-cpp](https://github.com/robloach/raylib-cpp). The available, 256-bit, perceptually uniform colour maps were derived from code and data published by [Anton Mikhailov of Google Research](https://blog.research.google/2019/08/turbo-improved-rainbow-colormap-for.html) and [Kenneth Moreland](https://www.kennethmoreland.com/color-advice/).

## Compilation
You will first need follow the installation instructions for raylib and raylib-cpp. Ensure the raylib static library is installed in `/usr/local/lib` and headers are copied to `/usr/local/include`. Then run the following commands to clone and build MandelbrotSet:

``` bash
git clone https://github.com/phlndrwd/MandelbrotSet.git
cd MandelbrotSet
mkdir build
cd build
cmake ..
make
```
## Usage
### Parameters
Alongside the executable is an `input/` directory containing the `params.txt` file. This file sets the parameters used by MandelbrotSet. See the table below for an explanation of these:

| Parameter Name  | Description                                                                                                                        |
|:----------------|:-----------------------------------------------------------------------------------------------------------------------------------|
| width           | Horizontal resolution graphical image.                                                                                             |
| height          | Vertical resolution of graphical image.                                                                                            |
| xMin            | Horizontal numerical minimum.                                                                                                      |
| xMax            | Horizontal numerical maximum.                                                                                                      |
| yMin            | Vertical numerical minimum.                                                                                                        |
| yMax            | Vertical numerical maximum.                                                                                                        |
| maxIter         | Maximum number of algorithm iterations.                                                                                            |
| threshold       | Arbitrary threshold value to escape the algorithm. Should be greater than 2.                                                       |
| colourMapOption | String selecting one of the colour maps out of "blackbody", "coolwarm", "greyscale", "plasma", "turbo", or "viridis".              |
| colourInvert    | Integer used as a boolean to invert ("1") or not invert ("0") the selected colour map.                                          |
| imagePath       | Absolute or relative path to the image written to disk. Images may be overwritten unless copied or changed from this location. |

### Mouse Control
Use the left mouse button to zoon into a section of the fractal image. Press and hold the button to draw a zoom box. The program will generate the image for your zoom selection area. You can save the image to a PPM file with the middle mouse button (not forgetting that the image is overwritten each time). You can reset to the initial zoom level with the right mouse button. See if you can zoom to the limits of numerical precision! Please see a couple of example images in the `examples/` directory. These have been converted to JPEG to save space, but were derived from PPM files produced by MandelbrotSet.
