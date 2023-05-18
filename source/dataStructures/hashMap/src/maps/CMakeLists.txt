# Create a variable to contain the source files
set(MAPS_H
StaticMap.h
StaticNode.h
)

# Create a variable to contain the source files
# set(MAPS_SRC
# StaticMap.cpp
# StaticNode.cpp
# )

# This command tells CMake to create an executable using the specified source code files
add_library(maps STATIC
            ${MAPS_H}
            # ${MAPS_SRC}
            )


# target_link_libraries(pointers PUBLIC
#                     common
#                     )

# Link in the Configuration File
target_include_directories(maps PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           )


