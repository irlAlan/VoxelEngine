#!/bin/bash

printf "Building VoxelEngineExample\n\n\n";

cmake -B build/;
cmake --build build;

printf "Running Example Application\n\n\n";

./build/VoxelExampleApp;
