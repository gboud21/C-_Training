# Set the C++ Standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(TARGET_NAME unordered_maps)

# Create a variable to contain the source files
set(UNORDERED_MAPS_H
    UnorderedMap.h
    UnorderedNode.h
    Hash.h
    )

# This command tells CMake to create an executable using the specified source code files
add_library(${TARGET_NAME} STATIC
            ${UNORDERED_MAPS_H}
            )


# target_link_libraries(pointers PUBLIC
#                     common
#                     )

# Link in the Configuration File
target_include_directories(${TARGET_NAME} PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           )

set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)

