#include <glad/glad.h>
#include <fmt/core.h>
#include <VEngine/Shaders.h>
#include <fstream>
#include <sstream>
#include <string_view>

Shaders::Shaders(std::string_view vertexPath, std::string_view fragmentPath){
  // get source from files
  std::string vertexSource, fragmentSource;
  std::ifstream vShaderFile{vertexPath.data()};
  std::ifstream fShaderFile{fragmentPath.data()};
  if(fShaderFile.is_open()){
    std::stringstream fragmentStream;
    fragmentStream << fShaderFile.rdbuf(); 
    fragmentSource = fragmentStream.str();
  }
  if(vShaderFile.is_open()){
    std::stringstream vertexStream;
    vertexStream << vShaderFile.rdbuf(); 
    vertexSource = vertexStream.str();
  }
  const char *vShaderCode = vertexSource.c_str();
  const char *fShaderCode = fragmentSource.c_str();

  unsigned int vertex, fragment;
  int success;
  char infoLog[512];

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vShaderCode, nullptr);
  glCompileShader(vertex);
  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
  if(!success){
    glGetShaderInfoLog(vertex, 512, NULL, infoLog); 
    fmt::println("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n{}",infoLog);
  }

  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fShaderCode, nullptr);
  glCompileShader(fragment);
  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
  if(!success){
    glGetShaderInfoLog(fragment, 512, NULL, infoLog); 
    fmt::println("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n{}",infoLog);
  }

  ID = glCreateProgram();
  glAttachShader(ID, vertex);
  glAttachShader(ID, fragment);
  glLinkProgram(ID);
  glGetProgramiv(ID, GL_LINK_STATUS, &success);
  if(!success){
    glGetProgramInfoLog(ID, 512, NULL, infoLog); 
    fmt::println("ERROR::SHADER::PROGRAM::LINK_FAILED\n{}",infoLog);
  }

  glDeleteShader(fragment);
  glDeleteShader(vertex);
}


void Shaders::useShaderProgram(){
  glUseProgram(ID);
}

void Shaders::unuseShaderProgram(){
  glUseProgram(0);
}

void Shaders::setBool(std::string_view name, bool value)const{glUniform1i(glGetUniformLocation(ID, name.data()), (int)value);}
void Shaders::setInt(std::string_view name, int value)const{glUniform1i(glGetUniformLocation(ID, name.data()), value);}
void Shaders::setFloat(std::string_view name, float value)const{glUniform1i(glGetUniformLocation(ID, name.data()), value);}
