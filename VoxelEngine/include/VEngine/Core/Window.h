#pragma once

#include <VEngine/Core/CoreIncludes.h>
#include <fmt/core.h>

namespace VEngine {

struct WindowConf{
  const string title{"Default Window"};
  const ivec2 dim{500, 450};
  const rgba backgroundCol{0.4f, 0.2f, 0.6f, 1.0f};
  const bool resizable{false};
};


class Window {
public:
  Window(stringv title, ivec2 dim, rgba backgroundCol, bool resizable);
  Window(const WindowConf& conf);

  void displayWindow();
  string getTitle() const { return _title; }
  ivec2 getDimensions() const { return _dimensions; }
  rgba getBackgroundCol() const { return _backgroundCol; }
  void clearScreen(rgba col);

  bool windowIsOpen();
  void exitWindow(stringv message, int exit_code);

private:
  GLFWwindow *window;
  string _title{"hey"};
  bool _resizable;
  ivec2 _dimensions{100, 100};
  rgba _backgroundCol{0.7f, 0.7f, 0.7f, 1.0f};

//private:

//void static viewportSizeChange(GLFWwindow* window, int width, int height);

public:
  // copy constructor
  Window(const Window &other)
      : _title(other._title), _dimensions(other._dimensions),
        _backgroundCol(other._backgroundCol) {}
  // copy assignment operator
  Window &operator=(const Window &other) {
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
