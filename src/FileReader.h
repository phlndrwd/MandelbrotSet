#ifndef FILEREADER_H
#define FILEREADER_H

#include <any>
#include <map>
#include <string>
#include <vector>

#include "Constants.h"

class FileReader {
public:
  FileReader();

  bool readText(std::vector<std::string>&);
  bool readParams(std::map<std::string, std::any>&);

private:
  std::vector<std::string> strToWords(const std::string&,
                                      const char separatorChar = consts::kSeparator) const;
  std::string strNoWhiteSpace(std::string&) const;
};

#endif // FILEREADER_H
