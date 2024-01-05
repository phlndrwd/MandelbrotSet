#ifndef FILEREADER_H
#define FILEREADER_H

#include <any>
#include <map>
#include <string>
#include <vector>

class FileReader {
public:
  FileReader();

  bool readText(std::string&, std::vector<std::string>&);
  bool readParams(std::map<std::string, std::any>&);

private:
};

#endif // FILEREADER_H
