#pragma once



// unsigned types
using u8  = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;

// signed types
using i8  = signed char;
using i16 = signed short;
using i32 = signed int;
using i64 = signed long long;

// float types
using f32 = float;
using f64 = double;


static_assert(sizeof(u8)  == 1, "Expected u8 to be 1 byte.");
static_assert(sizeof(u16) == 2, "Expected u16 to be 2 byte.");
static_assert(sizeof(u32) == 4, "Expected u32 to be 4 byte.");
static_assert(sizeof(u64) == 8, "Expected u64 to be 8 byte.");

static_assert(sizeof(i8)  == 1, "Expected i8 to be 1 byte.");
static_assert(sizeof(i16) == 2, "Expected i16 to be 2 byte.");
static_assert(sizeof(i32) == 4, "Expected i32 to be 4 byte.");
static_assert(sizeof(i64) == 8, "Expected i64 to be 8 byte.");

static_assert(sizeof(f32) == 4, "Expected f32 to be 4 byte.");
static_assert(sizeof(f64) == 8, "Expected f64 to be 8 byte.");

#define true 1
#define false 0

#ifdef __cplusplus
extern "C"{
#endif

#define VENGINE_API_EXPORTS (_WIN32 || _WIN64)

#if defined(_WIN32)
  #ifdef VENGINE_API_EXPORTS
    #define VEAPI __declspec(dllexport)
  #else
    #define VEAPI __declspec(dllimport)
  #endif
#else
  #define VENGINE_API 
#endif

#ifdef __cplusplus
}
#endif
