#ifndef COLOUR_H
#define COLOUR_H

#include <string>

class Colour {
public:
  Colour();
  Colour(unsigned char);
  Colour(unsigned char, unsigned char, unsigned char);

  Colour invert();

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
