cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# set(CMAKE_TOOLCHAIN_FILE "~/Downloads/vcpkg/scripts/buildsystems/vcpkg.cmake")

# set(CMAKE_TOOLCHAIN_FILE ON)

project(VoxelEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions("-Wall" "-g")

include_directories(${CMAKE_SOURCE_DIR}/include)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
#file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
# set(GLAD_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/glad/glad.c)
# file(GLOB VOXEL_HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/VEngine/*.h)

find_package(fmt CONFIG REQUIRED)
find_package(glfw3)
#find_package(glad)
find_package(Eigen3 3.4 REQUIRED)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/glad)

# add_executable(${PROJECT_NAME} ${SRC_FILES} ${GLAD_SRC} ${HEADER_FILES})

add_library(${PROJECT_NAME} SHARED
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


target_include_directories(${PROJECT_NAME} INTERFACE ./include)
target_include_directories(${PROJECT_NAME} INTERFACE ./src)

#set_target_properties(${PROJECT_NAME} PROPERTIES 
#  PUBLIC_HEADER ./include/API/VEngine.h
#  IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/samples/VoxelExampleApp/lib/VoxelEngine.so
#)
 # add_executable(${PROJECT_NAME} ${SRC_FILES} ${VOXEL_HEADER_FILES} )
 target_link_libraries(${PROJECT_NAME} INTERFACE 
  #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib/VoxelEngine.a>
  #$<INSTALL_INTERFACE:/include/VoxelEngine>
  glad
  fmt::fmt
  glfw
  Eigen3::Eigen
)
