#pragma once

#include <VEngine/Core/CoreDefines.h>
#include <mutex>

#define VRELEASE 0

#define LOG_INFO_ENABLED 1
#define LOG_WARN_ENABLED 1


// if we are in realease build
#if VRELEASE == 1
  #define LOG_TRACE_ENABLED 0
  #define LOG_DEBUG_ENABLED 0
#elif VRELEASE == 0 // in debug mode
  #define LOG_TRACE_ENABLED 1
  #define LOG_DEBUG_ENABLED 1
#endif

// Defining log levels
enum class LogLevel : u16{
  FATAL = 0, // things that dont allow application to run
  ERROR = 1, // serious  error but we can start and run (not correectly though)
  WARN  = 2, // sub-optimal issues
  INFO  = 3, // information logs
  DEBUG = 4, // debug level info for debug build only
  TRACE = 5 // verbose debug level
};

class  Log{
public:
  // move you inside the static Instance func
  b8 initLogging();
  void shutdownLogging();

  template<typename... T>
  VENGINE_API void VFATAL(str message, T ...args);
  template<typename... T>
  VENGINE_API void VERROR(str message, T ...args);
  template<typename... T>
  VENGINE_API void VWARN(str message, T ...args);
  template<typename... T>
  VENGINE_API void VINFO(str message, T ...args);
  template<typename... T>
  VENGINE_API void VDEBUG(str message, T ...args);
  template<typename... T>
  VENGINE_API void VTRACE(str message, T ...args);

  VENGINE_API static uptr<Log> Instance();
protected:
  Log() = default;
private:
  template<typename... T>
  VENGINE_API void _logOutput(LogLevel level, std::string message, T ...args);
  static uptr<Log> Instance_;
  static std::mutex m_;

public:
  ~Log() = default;
  Log(Log &&) = default;
  Log &operator=(Log &&) = default;
  Log(const Log &) = delete; // singletons should not be copyable
  Log &operator=(const Log &) = default; // should not be assignable
};