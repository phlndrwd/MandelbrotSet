#include "Colour.h"

#include "Constants.h"

Colour::Colour() {
  r_ = 0;
  g_ = 0;
  b_ = 0;
}

Colour::Colour(unsigned char grey) {
  r_ = grey;
  g_ = grey;
  b_ = grey;
}

Colour::Colour(unsigned char r, unsigned char g, unsigned char b) {
  r_ = r;
  g_ = g;
  b_ = b;
}

const unsigned char Colour::getR() const {
  return r_;
}

const unsigned char Colour::getG() const {
  return g_;
}

const unsigned char Colour::getB() const {
  return b_;
}

const std::string Colour::getStr() const {
  std::string ret = std::to_string(r_);
  unsigned rsz = consts::kMaxColourSize - ret.size();
  for (int i = 0; i < rsz; ++i) {
    ret.insert(0, consts::kSpace);
  }
  std::string gStr = std::to_string(g_);
  unsigned gsz = consts::kMaxColourSize - gStr.size();
  for (int i = 0; i < gsz; ++i) {
    gStr.insert(0, consts::kSpace);
  }
  std::string bStr = std::to_string(b_);
  unsigned bsz = consts::kMaxColourSize - bStr.size();
  for (int i = 0; i < bsz; ++i) {
    bStr.insert(0, consts::kSpace);
  }
  ret.append(consts::kSpace);
  ret.append(gStr);
  ret.append(consts::kSpace);
  ret.append(bStr);

  return ret;
}

void Colour::set(unsigned char r, unsigned char g, unsigned char b) {
  r_ = r;
  g_ = g;
  b_ = b;
}

