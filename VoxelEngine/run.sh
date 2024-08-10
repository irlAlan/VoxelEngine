#!/bin/bash

printf "Started VoxelEngine Build...\n\n\n";

cmake -B build/;
cmake --build build/;

printf "Moving VoxelEngine .so to VETest\n\n\n";

mv ./build/libVoxelEngine.so  ../VETest/lib/

printf "Copying includes over to samples\n\n\n";

cp -r include/ ../VETest/;

printf "Finished with VoxelEngine\n\n\n";

cd ../VETest/; ./run.sh;

