# VoxelEngine

Attempt to make a voxel engine using opengl

## Goals of engine
    - To be able to create and manage windows on linux, windows 
        - platform layer (abstracts from windows and linux)
        - Windowing, input, console interaction
    - Logging
    - File I/O
    - Application Layer(handles high level stuff like game loop and calling renderer etc)
    - Renderer/API abstraction layer (voxels) maybe raymarching
    - ECS
    - Physics engine
    - To be able to optimise and create voxels
    - To add realistic -ish physics to the voxels
    - Package in a dll for others to hopefully use
    - To learn more about program design and architecture as well as data structures


### Layers

    Platform Layer:
        - Windows, File I/O, Console I/O, Renderer API extensions, File I/O

    Core:
        - Logging, Assertions, Profiling, Data structures, async file i/o, engine config, memory allocation, math lib

    resource management:
        - Meshes, Materials, Images, Animations
etc

## Currently at
    - architecture of the engine
        - Currently making abstract classes for the interface that inherit behaviour from concrete classes through UML diagrams
        - Researching Program architecture

## TODO:
    - [ ] Add easier type defs and how to do logging and asserts in c++
    - [ ] refactor of current code
    - [ ] (potential) renaming of files and file structure
    - [ ] make cmake file more cross-platform


VoxelEngine (.do, .dll) <-editor <- test bed,  GameApplicaiton -> hot reloading

