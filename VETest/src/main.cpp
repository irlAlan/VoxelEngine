#include <VEngine/VEngine.h>
#include <VEngine/Core/Logger.h>
#include <fmt/core.h>

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
  return 0;
}
