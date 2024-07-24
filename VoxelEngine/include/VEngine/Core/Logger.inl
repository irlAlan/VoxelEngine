#include "VEngine/Core/CoreDefines.h"
#include <fmt/format.h>
#include <VEngine/Core/Asserts.h>
// #include <VEngine/Core/Logger.h>


//b8 Log::initLogging(){
//  // TODO: move this into Log::Instance
//  // created logging file
//  return true;
//}

//void Log::shutdownLogging(){
//  // TODO: keep a queue of logs then output immediatly ro console then print to file
//  // once over
//}

void report_assertion_failure(stringv expression, stringv message, stringv file, i32 line){
  Log::Instance()._logOutput(
    LogLevel::FATAL,"Assertion Failure: {}, in file: {} on line: {}\n",message, file, line);
}

template<typename ...T>
void Log::VFATAL(stringv message, T &&...args){
  _logOutput(LogLevel::FATAL,message, args...);
}

template<typename ...T>
  void Log::VERROR(stringv message, T &&...args){
  _logOutput(LogLevel::ERROR,message, args...);
}

template<typename ...T>
  void Log::VWARN(stringv message, T &&...args){
  _logOutput(LogLevel::WARN,message, args...);
}

template<typename ...T>
void Log::VINFO(stringv message, T &&...args){
  _logOutput(LogLevel::INFO,message, args...);
}

template<typename ...T> 
  void Log::VDEBUG(stringv message, T &&...args){
  _logOutput(LogLevel::DEBUG,message, args...);
}

template<typename ...T>
void Log::VTRACE(stringv message, T &&...args){
  _logOutput(LogLevel::TRACE,message, args...);
}

// TODO: Test this function
// https://stackoverflow.com/questions/4191089/how-to-unit-test-function-writing-to-stdout-stdcout
template<typename ...T>
void Log::_logOutput(LogLevel level, stringv message, T &&...args){
  string logStr[6]{"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};

  string formatStr{fmt::format("{} {}",logStr[static_cast<u16>(level)],message.data())};
  fmt::println(fmt::format(formatStr, args...));
}
