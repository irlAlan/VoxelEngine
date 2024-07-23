#include <glad/glad.h>
#include <fmt/core.h>
#include <VEngine/Shaders.h>
#include <fstream>
#include <sstream>

Shaders::Shaders(stringv vertexPath, stringv fragmentPath){
  // get source from files
  string vertexSource, fragmentSource;
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
    fmt::print("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n{}\n",infoLog);
  }

  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fShaderCode, nullptr);
  glCompileShader(fragment);
  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
  if(!success){
    glGetShaderInfoLog(fragment, 512, NULL, infoLog); 
    fmt::print("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n{}\n",infoLog);
  }

  ID = glCreateProgram();
  glAttachShader(ID, vertex);
  glAttachShader(ID, fragment);
  glLinkProgram(ID);
  glGetProgramiv(ID, GL_LINK_STATUS, &success);
  if(!success){
    glGetProgramInfoLog(ID, 512, NULL, infoLog); 
    fmt::print("ERROR::SHADER::PROGRAM::LINK_FAILED\n{}\n",infoLog);
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

void Shaders::setBool(stringv name, bool value)const{glUniform1i(glGetUniformLocation(ID, name.data()), (int)value);}
void Shaders::setInt(stringv name, int value)const{glUniform1i(glGetUniformLocation(ID, name.data()), value);}
void Shaders::setFloat(stringv name, float value)const{glUniform1i(glGetUniformLocation(ID, name.data()), value);}
