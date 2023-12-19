# Establish the minimum CMake version
# This ensures the following CMake functions are run with a compatible
# version of CMake
cmake_minimum_required(VERSION 3.14)

# This command specifies the project name
project(UtilitiesLibrary VERSION 1.0)

# Set the C++ Standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compile the components within this project
add_subdirectory(error)
add_subdirectory(logger)

# Complie the unit tests for this project
# add_subdirectory(test)