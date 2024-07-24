#pragma once

// using custom assertions for more control over logs and how errors are handled

#include "VEngine/Core/CoreDefines.h"
// comment out to disable assertions
#define VASSERTS_ENABLED

#ifdef VASSERTS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

VENGINE_API void report_assertion_failure(stringv expression, stringv message, stringv file, i32 line); // defined in Logger.inl

#define VASSERT(expr)                                        \
    {                                                        \
      if(expr){                                              \
      }else{                                                 \
        report_assertion_failure(#expr," ",__FILE__,__LINE__);\
        debugBreak();                                        \
      }                                                      \
    }



#define VASSERT_MSG(expr, msg)                                 \
    {                                                          \
      if(expr){                                                \
      }else{                                                   \
        report_assertion_failure(#expr,msg,__FILE__,__LINE__); \
        debugBreak();                                          \
      }                                                        \
    }

//defined when in debug mode
#ifdef _DEBUG
#define VASSERT_DEBUG(expr)                                  \
    {                                                        \
      if(expr){                                              \
      }else{                                                 \
        report_assertion_failure(#expr,"",__FILE__,__LINE__);\
        debugBreak();                                        \
      }                                                      \
    }
#else 
#define VASSERT_DEBUG(expr)  // does nothing
#endif

// when VASSERTS_ENABLED is commented out have these macros do nothing
#else
#define VASSERT_DEBUG(expr) // Does nothing
#define VASSERT_MSG(expr, msg) // Does nothing
#define VASSERT() // Does Nothing
//
#endif // VASSERTS_ENABLED
