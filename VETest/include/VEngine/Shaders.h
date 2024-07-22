#ifndef SHADER_H
#define SHADER_H

#include <string_view>

class Shaders{
public:
  // program ID
  unsigned int ID;

  Shaders(std::string_view vertexPath, std::string_view fragmentPath);
  void useShaderProgram();
  void unuseShaderProgram();
  //util funcs
  void setBool(std::string_view name, bool value)const;
  void setInt(std::string_view name, int value)const;
  void setFloat(std::string_view name, float value)const;
};

#endif
