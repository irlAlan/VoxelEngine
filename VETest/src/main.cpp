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
  uptr<VEngine::Log> logger{VEngine::Log::Instance()};
  logger->VTRACE("not good %s", "other");
  logger->VFATAL("not good", "other");
  logger->VERROR("not good", "other");
  logger->VINFO("not good", "other");
  logger->VWARN("not good", "other");
  logger->VDEBUG("haha","nein");
  return 0;
}
