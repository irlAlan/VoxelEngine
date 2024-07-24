#pragma once

#include "VEngine/Core/CoreDefines.h"

class Shaders{
public:
  // program ID
  unsigned int ID;

  Shaders(stringv vertexPath, stringv fragmentPath);
  void useShaderProgram();
  void unuseShaderProgram();
  //util funcs
  void setBool(stringv name, bool value)const;
  void setInt(stringv name, int value)const;
  void setFloat(stringv name, float value)const;
};
