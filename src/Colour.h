/******************************************************************************
* MandelbrotSet                                                               *
*                                                                             *
* (C) Copyright 2024, Phil Underwood. All rights reserved.                    *
*                                                                             *
* This software is licensed under the terms of the 3-Clause BSD License       *
* which can be obtained from https://opensource.org/license/bsd-3-clause/.    *
******************************************************************************/

#ifndef COLOUR_H
#define COLOUR_H

#include <string>

class Colour {
public:
  Colour();
  explicit Colour(unsigned char, unsigned char, unsigned char);

  void invert();

  const unsigned char getR() const;
  const unsigned char getG() const;
  const unsigned char getB() const;

  const std::string getStr() const;

  void set(unsigned char, unsigned char, unsigned char);

private:
  unsigned char r_;
  unsigned char g_;
  unsigned char b_;
};

#endif // COLOUR_H
