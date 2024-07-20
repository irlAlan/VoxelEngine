#include <VEngine/VEngine.h>
// #include <memory>
#include <stdexcept>
#include <fmt/core.h>

namespace VEngine{

VEngine *VEngine::_Instance = nullptr;

VEngine::VEngine() 
{
  if(!_Instance){
    _Instance = this;
  }
  else{
    throw std::runtime_error("VEngine already created.");
  }
}

VEngine::~VEngine() {
}

void VEngine::onInit() {}

void VEngine::onQuit() {}

void VEngine::run() {}

void VEngine::quit() {}

VEngine* VEngine::get(){
  return _Instance;
}

}
