#include <VEngine/VEngine.h>
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
  Engine engine;
  engine.run();
  return 0;
}
