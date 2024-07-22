#pragma once

#include <VEngine/Core/CoreDefines.h>
// #include <memory>

namespace VEngine
{

class VENGINE_API VEngine {
public:
  VEngine();
  virtual ~VEngine();

  virtual void onInit();
  virtual void onQuit();

  void run();
  void quit();
public:
  static VEngine *get();
private:
  static VEngine* _Instance;
};
}


//namespace VEngine {
//
//class VEngine {
//public:
//  void Init();
//  void Cleanup();
//
//  // state management
//
//  // Event handling
//  void HandleEvents();
//  void Update();
//  void Draw();
//  bool Running() { return _running; }
//
//private:
//  bool _running;
//  // Window win{"Hey Bozo", {500, 500}};
//
//};
// } // namespace VEngine
//
//
