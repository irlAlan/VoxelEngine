#include "VEngine/Core/CoreDefines.h"
#include <fmt/format.h>
#include <memory>

namespace VEngine{

uptr<Log> Log::Instance_ = nullptr;
std::mutex Log::m_;


VENGINE_API uptr<Log> Log::Instance(){
 std::lock_guard<std::mutex> lock(m_);
  if (Instance_ == nullptr){
      Instance_ = std::make_unique<Log>(Log());
  }
  return std::move(Instance_); // since ints a unique_ptr and cannot be copied but moved
}



  template<typename ...T>
  VENGINE_API void Log::prnt(T &...args){
    auto printArgs{
      [](const auto &arg){
        fmt::println("{}", arg);
      }
    };
    (printArgs(args), ...);
  }


b8 initLogging(){
  // TODO: move this into Log::Instance
  // created logging file
  return true;
}

void shutdownLogging(){
  // TODO: keep a queue of logs then output immediatly ro console then print to file
  // once over
}


template<typename ...T>
VENGINE_API void Log::VFATAL(str messages, T ...args){
  auto formatArgs{
    [&messages, this](const auto &arg){
      _logOutput(LogLevel::FATAL,messages, arg);
    }
  };
  (formatArgs(args), ...);
}


template<typename... T>
VENGINE_API void VERROR(str message, T ...args){

}

template<typename... T>
VENGINE_API void VWARN(str message, T ...args){

}

template<typename... T>
VENGINE_API void VINFO(str message, T ...args){

}

template<typename... T> VENGINE_API void VDEBUG(str message, T ...args){

}

template<typename... T>
VENGINE_API void VTRACE(str message, T ...args){

}

// TODO: Test this function
// https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
template<typename ...T>
VENGINE_API void Log::_logOutput(LogLevel level, str message, T &...args){
  str logStr[6]{"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};

  str formatStr{logStr[static_cast<u16>(level)]+message};
  auto formatArgs{
    [&formatStr](const auto &arg){
      formatStr.append(arg);
      fmt::println(formatStr);
    }
  };
  (formatArgs(args), ...);
}
}
