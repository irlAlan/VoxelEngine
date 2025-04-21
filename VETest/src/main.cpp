// #include <GLFW/glfw3.h>
// #include <VEngine/Core/Asserts.h>
#include <VEngine/Core/Logger.h>
#include <VEngine/Core/Window.h>
#include <VEngine/VEngine.h>
#include <fmt/core.h>
#include <glad/glad.h>

#include "VEngine/Core/CoreIncludes.h"

class Engine : public VEngine::VEngine {
 public:
  Engine() {}
  ~Engine() { fmt::println("ENGINE destruct called"); }
  void onInit() override { fmt::println("On initialise"); }
  void onQuit() override { fmt::println("Quiting"); }
  void run() { fmt::println("RUNNING"); }
  void quit() {}
};

int main() {
  // Log::Instance().VTRACE("not good {}", "other");

  VEngine::WindowConf winConf{"Hey there", {600, 500}, {1, 1, 1, 1}, false};
  VEngine::Window win{winConf};
  glEnable(GL_DEPTH_TEST);
  constexpr float cubeVerts[] = {
      0.0f, 0.0f,
      0.0f,  // 111 -- 0
      1.0f, 0.0f,
      0.0f,  // 011 -- 1
      1.0f, 0.0f,
      1.0f,  // 010 -- 2
      0.0f, 0.0f,
      1.0f,  // 110 -- 3

      1.0f, 1.0f,
      0.0f,  // 001 -- 4
      1.0f, 1.0f,
      1.0f,  // 000 -- 5
      0.0f, 1.0f,
      1.0f,  // 100 -- 6
      0.0f, 1.0f,
      0.0f,  // 101 -- 7
  };

  constexpr uint indicies[] = {// Top
                               0, 1, 2, 2, 3, 0,

                               // front
                               3, 2, 5, 5, 6, 3,

                               // right
                               7, 0, 3, 3, 6, 7,

                               // back
                               4, 1, 0, 0, 7, 4,

                               // left
                               5, 2, 1, 1, 4, 5,

                               // bottom
                               4, 7, 6, 6, 5, 4};
  uint VBO, VAO, EBO;

  glGenBuffers(1, &VBO);
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies,
               GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVerts), &cubeVerts, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

  uint voxelBuffer;
  glGenBuffers(1, &voxelBuffer);
  glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, voxelBuffer);

  while (true) {
    win.displayWindow();
  }
  return 0;
}
