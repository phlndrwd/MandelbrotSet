/******************************************************************************
* MandelbrotSet                                                               *
*                                                                             *
* (C) Copyright 2024, Phil Underwood. All rights reserved.                    *
*                                                                             *
* This software is licensed under the terms of the 3-Clause BSD License       *
* which can be obtained from https://opensource.org/license/bsd-3-clause/.    *
******************************************************************************/

#include "FileReader.h"

#include "Constants.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>

namespace {
std::string strNoWhiteSpace(std::string input) {
  input.erase(std::remove_if(input.begin(), input.end(), [](unsigned char x) {
      return std::isspace(x);
  }), input.end());
  return input;
}

std::string strToLower(std::string input) {
  std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {
    return std::tolower(c);
  });
  return input;
}

bool strToBool(std::string input) {
  std::string cleanStr = strNoWhiteSpace(strToLower(input));
  if ((cleanStr.size() == 1 && cleanStr == "1") || (cleanStr.size() == 4 && cleanStr == "true")) {
    return true;
  } else if ((cleanStr.size() == 1 && cleanStr == "0") || (cleanStr.size() == 5 && cleanStr == "false")) {
    return false;
  } else {
    throw std::invalid_argument("ERROR in FileReader::strToBool: Input of \"" + input + "\" is invalid.");
  }
}
std::vector<std::string> strToWords(const std::string& inputStr, const char separatorChar = consts::kSeparator)  {
  std::stringstream stringStream(inputStr);
  std::string word = "";
  std::vector<std::string> words;
  while (std::getline(stringStream, word, separatorChar)) {
    words.push_back(word);
  }
  return words;
}
}

FileReader::FileReader() {}

bool FileReader::readText(std::string& path, std::vector<std::string>& lines) {
  try {
    std::string line;
    std::ifstream fileIn(path);
    if (fileIn.is_open()) {
      while (std::getline(fileIn, line)) {
        lines.push_back(line);
      }
      fileIn.close();
      return true;
    }
    std::cout << "Error in FileReader::readText: File path \"" + path + "\" is not valid." << std::endl;
    return false;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    return false;
  }
}

bool FileReader::readParams(std::map<std::string, std::any>& values) {
  std::vector<std::string> lines;
  std::string paramsPath = consts::kInputPath + consts::kParamFile;
  if (readText(paramsPath, lines) == true) {
    for (auto& line : lines) {
      std::string lineNoWhite = strNoWhiteSpace(line);
      std::vector<std::string> words = strToWords(lineNoWhite);
      std::string key = words[0];
      if (words.size() == 2) {
        if (key == "maxIter" || key == "width" || key == "height") {
          unsigned param = std::stoul(words[1]);
          values.insert({key, param});
        } else if (key == "xMin" || key == "xMax" || key == "yMin" ||
                   key == "yMax" || key == "threshold") {
          double param = std::stod(words[1]);
          values.insert({key, param});
        } else if (key == "colourInvert") {
          bool param = strToBool(words[1]);
          values.insert({key, param});
        } else {
          std::string param = strToLower(words[1]);
          values.insert({key, param});
        }
      } else {
        return false;
      }
    }
    return true;
  } else {
    return false;
  }
}
