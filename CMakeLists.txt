# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(SquarePrintPattern VERSION 1.0)

# Set the C standard to use
set(CMAKE_C_STANDARD 99)

# Add an executable target with the source file
add_executable(SquarePrintPattern main.c)
