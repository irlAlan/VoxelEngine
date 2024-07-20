#!/bin/bash

prinf "Started VoxelEngine Build...\n\n\n";

cmake -B build/;
cmake --build build/;

printf "Moving VoxelEngine .so to samples\n\n\n";

mv ./build/libVoxelEngine.so ./samples/VoxelExampleApp/lib/;

printf "Copying includes over to samples\n\n\n";

cp -r include samples/VoxelExampleApp/ ;

printf "Finished with VoxelEngine\n\n\n";

cd ./samples/VoxelExampleApp; ./run.sh;
