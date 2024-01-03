#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <cctype>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace utils {
  std::vector<std::string> strToWords(const std::string inputStr,
                                      const char separatorChar);

  std::string strNoWhiteSpace(std::string input);
  std::string strTolower(std::string input);

  bool strToBool(std::string input);
  bool fileExists(std::string path);

  template<typename T1, typename T2>
  std::vector<T1> extractKeys(std::map<T1, T2> const& inputMap);

  template<typename T>
  int findPosInVector(std::vector<T> vector, T searchTerm);

  template<typename T>
  bool findInVector(std::vector<T> vector, T searchTerm);
}

#endif // UTILS_H
