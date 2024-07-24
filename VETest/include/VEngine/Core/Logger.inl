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
VENGINE_API void Log::prnt(stringv message, T &&...args){
  fmt::println(fmt::format(message, args...));
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
VENGINE_API void Log::VFATAL(stringv message, T ...args){
  auto formatArgs{
    [&message, this](const auto &arg){
      _logOutput(LogLevel::FATAL,message, arg);
    }
  };
  (formatArgs(args), ...);
}


template<typename... T>
VENGINE_API void Log::VERROR(stringv message, T ...args){
  auto formatArgs{
    [&message, this](const auto &arg){
      _logOutput(LogLevel::ERROR,message, arg);
    }
  };
  (formatArgs(args), ...);
}

template<typename... T>
VENGINE_API void Log::VWARN(stringv message, T ...args){
  auto formatArgs{
    [&message, this](const auto &arg){
      _logOutput(LogLevel::WARN,message, arg);
    }
  };
  (formatArgs(args), ...);
}

template<typename... T>
VENGINE_API void Log::VINFO(stringv message, T ...args){
  auto formatArgs{
    [&message, this](const auto &arg){
      _logOutput(LogLevel::INFO,message, arg);
    }
  };
  (formatArgs(args), ...);
}

template<typename... T> VENGINE_API void Log::VDEBUG(stringv message, T ...args){
  auto formatArgs{
    [&message, this](const auto &arg){
      _logOutput(LogLevel::DEBUG,message, arg);
    }
  };
  (formatArgs(args), ...);
}

template<typename... T>
VENGINE_API void Log::VTRACE(stringv message, T ...args){
  auto formatArgs{
    [&message, this](const auto &arg){
      _logOutput(LogLevel::TRACE,message, arg);
    }
  };
  (formatArgs(args), ...);
}

// TODO: Test this function
// https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
template<typename ...T>
VENGINE_API void Log::_logOutput(LogLevel level, stringv message, T &...args){
  string logStr[6]{"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};

  string formatStr{logStr[static_cast<u16>(level)]+message.data()};
  auto formatArgs{
    [&formatStr](const auto &arg){
      formatStr.append(arg);
      fmt::println(formatStr);
    }
  };
  (formatArgs(args), ...);
}
}
