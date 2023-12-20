#include "FileReader.h"

#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>

FileReader::FileReader() {}

bool FileReader::readText(std::vector<std::string>& lines) {
  try {
    std::string line;
    std::ifstream fileIn(consts::kInputPath + consts::kParamFile);
    if (fileIn.is_open()) {
      while (std::getline(fileIn, line)) {
        lines.push_back(line);
      }
      fileIn.close();
    }
    return true;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    return false;
  }
}

bool FileReader::readParams(std::map<std::string, std::any>& values) {
  std::vector<std::string> lines;
  if (readText(lines) == true) {
    for (auto& line : lines) {
      std::string lineNoWhite = strNoWhiteSpace(line);
      std::vector<std::string> words = strToWords(lineNoWhite);
      std::string key = words[0];
      if (words.size() == 2) {
        if (key == "maxIter" || key == "width" || key == "height") {
          unsigned param = std::stoul(words[1]);
          values.insert({key, param});
        } else if (key == "xMin" || key == "xMax" ||
                   key == "yMin"|| key == "yMax") {
          double param = std::stod(words[1]);
          values.insert({key, param});
        } else if (key == "colourInvert") {
          bool param = std::stoi(words[1]);
          values.insert({key, param});
        } else {
          std::string param = words[1];
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

std::vector<std::string> FileReader::strToWords(const std::string& inputStr,
                                                const char separatorChar) const {
  std::stringstream stringStream(inputStr);
  std::string word = "";
  std::vector<std::string> words;
  while (std::getline(stringStream, word, separatorChar)) {
    words.push_back(word);
  }
  return words;
}

std::string FileReader::strNoWhiteSpace(std::string& input) const {
  input.erase(std::remove_if(input.begin(), input.end(), [](unsigned char x) {
      return std::isspace(x);
  }), input.end());
  return input;
}
