cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(VoxelExampleApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions("-Wall" "-g")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

find_package(fmt CONFIG REQUIRED)
find_package(glfw3)

include(FetchContent)
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm
  GIT_TAG 1.0.1
)
FetchContent_MakeAvailable(glm)


add_library(VoxelEngine SHARED IMPORTED)

# Provide the full path to the library, so CMake knows where to find it.
set_target_properties(VoxelEngine PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/libVoxelEngine.so)


add_executable(VoxelExampleApp ${SRC_FILES})

target_link_libraries(VoxelExampleApp PUBLIC glfw fmt::fmt glm::glm)
