cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(VoxelEngine)

set(LIB_NAME "VoxelEngine")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions("-Wall" "-g")

include_directories(${CMAKE_SOURCE_DIR}/include)

# add dependencies
include(cmake/CPM.cmake)

CPMAddPackage("gh:fmtlib/fmt#7.1.3")

CPMAddPackage(
  NAME Eigen
  VERSION 3.2.8
  URL https://gitlab.com/libeigen/eigen/-/archive/3.2.8/eigen-3.2.8.tar.gz
  # Eigen's CMakelists are not intended for library use
  DOWNLOAD_ONLY YES 
)

CPMAddPackage(
  NAME GLFW
  GITHUB_REPOSITORY glfw/glfw
  GIT_TAG 3.3.2
  OPTIONS
    "GLFW_BUILD_TESTS OFF"
    "GLFW_BUILD_EXAMPLES OFF"
    "GLFW_BULID_DOCS OFF"
)

if(Eigen_ADDED)
  add_library(Eigen INTERFACE IMPORTED)
  target_include_directories(Eigen INTERFACE ${Eigen_SOURCE_DIR})
endif()

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
  ./include/VEngine/Core/CoreDefines.h
  ./include/VEngine/Core/CoreIncludes.h
  ./include/VEngine/Shapes.h
  ./include/VEngine/Window.h
  ./include/VEngine/Shaders.h
  ./include/VEngine/VEngine.h
)

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${LIB_NAME} PUBLIC ./src)

target_link_libraries(${LIB_NAME} INTERFACE glad fmt::fmt glfw Eigen)

#target_link_libraries(${LIB_NAME} PUBLIC 
#  glad
#  fmt::fmt
#  glfw
#  Eigen3::Eigen
#)
