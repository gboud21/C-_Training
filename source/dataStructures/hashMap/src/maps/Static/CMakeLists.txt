# Set the C++ Standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create a variable to contain the source files
set(STATIC_MAPS_H
StaticMap.h
StaticNode.h
)

# Create a variable to contain the source files
set(STATIC_MAPS_SRC
# StaticMap.cpp
# StaticNode.cpp
)

# This command tells CMake to create an executable using the specified source code files
add_library(static_maps STATIC
            ${STATIC_MAPS_H}
            # ${STATIC_MAPS_SRC}
            )


# target_link_libraries(pointers PUBLIC
#                     common
#                     )

# Link in the Configuration File
target_include_directories(static_maps PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           )

set_target_properties(static_maps PROPERTIES LINKER_LANGUAGE CXX)

