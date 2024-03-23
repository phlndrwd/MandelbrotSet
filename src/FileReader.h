/******************************************************************************
* MandelbrotSet                                                               *
*                                                                             *
* (C) Copyright 2024, Phil Underwood. All rights reserved.                    *
*                                                                             *
* This software is licensed under the terms of the 3-Clause BSD License       *
* which can be obtained from https://opensource.org/license/bsd-3-clause/.    *
******************************************************************************/

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
