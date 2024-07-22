#pragma once

#include <VEngine/Core/CoreIncludes.h>
#include <fmt/core.h>

namespace VEngine {

struct WindowConf{
  const std::string title{"Default Window"};
  const Vec2d dim{{500, 450}};
  const RGBA backgroundCol{{0.4f, 0.2f, 0.6f, 1.0f}};
  const bool resizable{false};
};


class Window {
public:
  Window(std::string title, Vec2d dim, RGBA backgroundCol, bool resizable);
  Window(const WindowConf& conf);

  void displayWindow();
  std::string getTitle() const { return _title; }
  Vec2d getDimensions() const { return _dimensions; }
  RGBA getBackgroundCol() const { return _backgroundCol; }
  void clearScreen(RGBA col);

  bool windowIsOpen();
  void exitWindow(std::string message, int exit_code);

private:
  GLFWwindow *window;
  std::string _title{"hey"};
  bool _resizable;
  Vec2d _dimensions{100, 100};
  RGBA _backgroundCol{0.7f, 0.7f, 0.7f, 1.0f};

//private:

//void static viewportSizeChange(GLFWwindow* window, int width, int height);

public:
  // copy constructor
  Window(const Window &other)
      : _title(other._title), _dimensions(other._dimensions),
        _backgroundCol(other._backgroundCol) {}
  // copy assignment operator
  Window &operator=(const VEngine::Window &other) {
    if (this != &other) {
      *this = other;
    }
    return *this;
  }

  // Move Constructor
  Window(Window &&other) noexcept
      : _title(other._title), _dimensions(other._dimensions),
        _backgroundCol(other._backgroundCol) {
    other._title = "";
    other._backgroundCol = {};
    other._dimensions = {};
  }
  // Move assignment operator
  Window &operator=(Window &&other) {
    if (this != &other) {
      _title = other._title;
      _dimensions = other._dimensions;
      _backgroundCol = other._backgroundCol;

      other._title = "";
      other._dimensions = {};
      other._backgroundCol = {};
    }
    return *this;
  }
  ~Window(){
    exitWindow("closing window", 0);
  }
};
} // namespace VEngine
