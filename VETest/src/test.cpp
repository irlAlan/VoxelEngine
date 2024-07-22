#include <VEngine/Window.h>

int main(){
  // define a window
  VEngine::WindowConf conf{"WHATTT",{900, 533},{0.0f, 0.0f, 0.0f, 1.0f}, false};
  VEngine::Window window{conf};
  // check if the window is open
  float cubeVB[] = {
    -0.5f, -0.5f, -0.5f, // 0 left bottom
    -0.5f,  0.5f, -0.5f, // 1 left top
     0.5f,  0.5f, -0.5f, // 2 right top
     0.5f, -0.5f, -0.5f, // 3 right bottom
    // back cube
     0.5f, -0.5f,  0.5f, // 4 back bottom right
     0.5f,  0.5f,  0.5f, // 5 back top right
    -0.5f,  0.5f,  0.5f, // 6 back top left
    -0.5f, -0.5f,  0.5f  // 7 back bottom left
  };

  int cubeEB[] = {
    0,1,2,
    2,3,0
  };

  while(window.windowIsOpen()){
    window.clearScreen({0.5f, 0.3f, 0.6f, 1.0f});
    window.displayWindow();
  }
}
