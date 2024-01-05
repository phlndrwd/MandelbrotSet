#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <vector>

namespace enums {
  enum eColourMapOptions {
    eBlackBody,
    eCoolWarm,
    eGreyScale,
    ePlasma,
    eTurbo,
    eViridis
  };
}  // namespace enums

namespace consts {
  const std::vector<std::string> kColourMapOpts{
    "blackbody",
    "coolwarm",
    "greyscale",
    "plasma",
    "turbo",
    "viridis"
  };

  const char kSeparator = ',';

  const unsigned kNumberOfColours = 256;

  const unsigned kMaxColourSize = 3;

  const std::string kSpace = " ";
  const std::string kBigSpace = "  ";
  const std::string kInputPath = "./input/";
  const std::string kParamFile = "params.txt";
}  // namespace consts

#endif // CONSTANTS_H
