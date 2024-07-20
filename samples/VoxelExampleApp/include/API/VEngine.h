#ifndef VENGINE_API_H
#define VENGINE_API_H

#ifdef __cplusplus
extern "C"{
#endif

#define VENGINE_API_EXPORTS (_WIN32 || _WIN64)

#ifdef _WIN32
  #ifdef VENGINE_API_EXPORTS
    #define VENGINE_API __declspec(dllexport)
  #else
    #define VENGINE_API __declspec(dllimport)
  #endif
#else
  #define VENGINE_API 
#endif

#ifdef __cplusplus
}
#endif

#endif
