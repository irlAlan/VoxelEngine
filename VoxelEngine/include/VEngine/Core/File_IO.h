#pragma once

// Handle File io
#include "VEngine/Core/CoreDefines.h"
#include <VEngine/Core/CoreIncludes.h>

class File_IO {

public:
  File_IO() = default;

  string readFile(stringv fileDir);
  b8 isDir(stringv dir);
  b8 isFile(stringv dir);

private:
  string defaultLocation;
};
