#include <VEngine/Window.h>

namespace VEngine{

  Window::Window(const WindowConf& conf)
    : Window(conf.title, conf.dim, conf.backgroundCol, conf.resizable)
  {}


  Window::Window(std::string title, Vec2d dim, RGBA backgroundCol, bool resizable)
  : _title(title), _resizable(resizable), _dimensions(dim), _backgroundCol(backgroundCol)
  {
    if(glfwInit() == GLFW_FALSE){
      exitWindow("Could not init glfw",-1);
    }

    glfwWindowHint(GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #if defined(__APPLE__)
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    window = glfwCreateWindow(dim.x(), dim.y(),title.c_str(), nullptr,nullptr);
    if (window == NULL)
    {
      exitWindow("Could not create Window", -1);
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      exitWindow("Failed to initialize GLAD", -1);
    }
    glViewport(0, 0, dim.x(),dim.y());
    // glfwSetFramebufferSizeCallback(window, viewportSizeChange);
  }

  void Window::displayWindow(){
      clearScreen(_backgroundCol);

    // move to event handler
      glfwPollEvents();
    // move to window updates
      glfwSwapBuffers(window);
  }

  void Window::clearScreen(RGBA col={1.0f,1.0f,1.0f,1.0f}){
      // glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClearColor(col.x(), col.y(), col.z(), col.w());
      glClear(GL_COLOR_BUFFER_BIT);
  }

  bool Window::windowIsOpen(){
    return !glfwWindowShouldClose(window);
  }

  //void viewportSizeChange(GLFWwindow* window, int width, int height){
  //  glViewport(0,0, width, height);
  //}

  void Window::exitWindow(std::string message, int exit_code){
    fmt::print("EXIT MESSAGE: {} \n", message);
    glfwTerminate();
    exit(exit_code);
  }
}
