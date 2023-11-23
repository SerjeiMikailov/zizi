#!/bin/bash

source_dir="src"
output_dir="build"
compiler="g++"
compile_options="-c"

mkdir -p "$output_dir"

# Compile all .cpp files in $source_dir to .o files in $output_dir
for source_file in "$source_dir"/*.cpp; do
    file_name=$(basename "$source_file" .cpp)

    $compiler $compile_options "$source_file" -o "$output_dir/$file_name.o"

    if [ $? -ne 0 ]; then
        echo "Error compiling $source_file"
        exit 1
    fi
done

cd src

clang -c sysinfo.c -o ../build/sysinfo.o
clang -c reworks.c -o ../build/reworks.o

cd ..

# Change to the output directory and compile all .o files into the "main" executable
cd "$output_dir"
clang++ *.o -o main

# Run the compiled program
./main

echo "Compilation completed successfully"
