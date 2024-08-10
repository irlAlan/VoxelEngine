cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(VoxelEngine)

set(LIB_NAME "VoxelEngine")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_definitions("-Wall" "-g")

include_directories(${CMAKE_SOURCE_DIR}/include)


add_subdirectory(${CMAKE_SOURCE_DIR}/lib/glad)


add_library(${LIB_NAME} SHARED
  ./src/glad/glad.c
  ./src/VEngine/VEngine.cpp
  ./src/Window.cpp
  ./src/Shapes.cpp
  ./src/Shaders.cpp

  # HEADER files
  ./include/glad/glad.h
  ./include/KHR/khrplatform.h
  ./include/VEngine/Core/Logger.h
  ./include/VEngine/Core/Logger.inl
  ./include/VEngine/Core/Asserts.h
  ./include/VEngine/Core/CoreDefines.h
  ./include/VEngine/Core/CoreIncludes.h
  ./include/VEngine/Shapes.h
  ./include/VEngine/Core/Window.h
  ./include/VEngine/Shaders.h
  ./include/VEngine/VEngine.h

)

# add dependencies
# include(cmake/CPM.cmake)
include(FetchContent)

# CPMAddPackage("gh:fmtlib/fmt#7.1.3")
# CPMAddPackage("gh:glfw/glfw#3.4")
#CPMAddPackage("gh:iauns/cpm-glm#1.0.1")
#CPMAddPackage("gl:libeigen/eigen#3.4.0")



FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG 11.0.2
)
FetchContent_MakeAvailable(fmt)



FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw
  GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)



FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm
  GIT_TAG 1.0.1
)
FetchContent_MakeAvailable(glm)
#CPMAddPackage(
#  NAME Eigen
#  VERSION 3.2.8
#  URL https://gitlab.com/libeigen/eigen/-/archive/3.2.8/eigen-3.2.8.tar.gz
#  # Eigen's CMakelists are not intended for library use
#  DOWNLOAD_ONLY YES 
#)
#
#CPMAddPackage(
#  NAME GLFW
#  GITHUB_REPOSITORY glfw/glfw
#  GIT_TAG 3.3.2
#  OPTIONS
#    "GLFW_BUILD_TESTS OFF"
#    "GLFW_BUILD_EXAMPLES OFF"
#    "GLFW_BULID_DOCS OFF"
#)
#
#if(Eigen_ADDED)
#  add_library(Eigen INTERFACE IMPORTED)
#  target_include_directories(Eigen INTERFACE ${Eigen_SOURCE_DIR})
#endif()

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${LIB_NAME} PUBLIC ./src)

target_link_libraries(${LIB_NAME} PUBLIC glad fmt::fmt glfw glm::glm)

#target_link_libraries(${LIB_NAME} PUBLIC 
#  glad
#  fmt::fmt
#  glfw
#  Eigen3::Eigen
#)
