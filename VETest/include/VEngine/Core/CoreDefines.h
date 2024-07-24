#pragma once

#include <VEngine/Core/CoreIncludes.h>

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

// bool types
using b8 = char;
using b32 = int;

// string wrapper
using string = std::string;
using stringv = std::string_view;

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

// boolean values
#define true 1
#define false 0

// memory pointers defs
template <typename T>
using uptr = std::unique_ptr<T>;

/* Matrix<2, 1>
 * [int]
 * [int]
*/
// using Vec2d = Eigen::Matrix<int, 2,1>;
using ivec2 = glm::ivec2;

/* Matrix<1, 4>
 * [float][float][float][float]
*/
//using RGBA = Eigen::Matrix<float, 1, 4>;
using rgba = glm::fvec4;

#ifdef __cplusplus
extern "C"{
#endif

#define VENGINE_API_EXPORTS (_WIN32 || _WIN64)

#if defined(_WIN32)
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
