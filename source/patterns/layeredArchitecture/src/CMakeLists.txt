# Establish the minimum CMake version
# This ensures the following CMake functions are run with a compatible
# version of CMake
cmake_minimum_required(VERSION 3.14)

# This command specifies the project name
project(LayerArchitectureExample VERSION 1.0)

# Set the C++ Standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(common)
add_subdirectory(data)
add_subdirectory(persistence)
add_subdirectory(business)
add_subdirectory(presentation)
add_subdirectory(app)

add_subdirectory(test)