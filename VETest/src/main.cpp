#include <VEngine/Core/Asserts.h>
#include <VEngine/VEngine.h>
#include <VEngine/Core/Logger.h>
#include <fmt/core.h>
#include <VEngine/Core/Window.h>

class Engine : public VEngine::VEngine
{
public:

  Engine(){}
  ~Engine(){
    fmt::println("ENGINE destruct called");
  }
  void onInit() override{fmt::println("On initialise");}
  void onQuit() override {fmt::println("Quiting");}
  void run(){fmt::println("RUNNINGJK");}
  void quit(){}
};

int main()
{
  // Log::Instance().VTRACE("not good {}", "other");

  VEngine::WindowConf winConf{"Hey there",{600, 500},{1,1,1,1},false};
  VEngine::Window win{winConf};
  while(true){
    win.displayWindow();
  }
  return 0;
}
