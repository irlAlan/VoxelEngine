# VoxelEngine

Attempt to make a voxel engine using opengl

## Goals of engine
    - To have a fully functional game engine thats able to render voxels with relative ease to the screen
    - What I want to be added:
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
        - Windows, File I/O, Console I/O, Renderer API extensions

    Core:
        - Logging, Assertions, Profiling, Data structures, async file i/o, engine config, math lib

    resource management:
        - Meshes, Materials, Images, Animations
etc

## Currently at
    - File I/O wrapper
    - architecture of the engine
        - Currently making abstract classes for the interface that inherit behaviour from concrete classes through UML diagrams
        - Researching Program architecture

## Finished
    - Logging and assertions

## TODO:
    - [x] Add easier type defs and how to do logging and asserts in c++
    - [ ] Add Tests
    - [ ] refactor of current code
    - [ ] (potential) renaming of files and file structure
    - [ ] make cmake file more cross-platform


VoxelEngine (.so, .dll)
editor ui is going to be seperate to actual engine and will probably be made using c# and avaloniaUI if i decide to add ui

