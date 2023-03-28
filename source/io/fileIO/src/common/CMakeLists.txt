# Create a variable to contain the source files
set(COMMON_H
    Error.h
    )

# Create a variable to contain the source files
set(COMMON_SRC
Error.cpp
)

# This command tells CMake to create an executable using the specified source code files
add_library(common STATIC
            ${COMMON_H}
            ${COMMON_SRC}
            )

# Link in the Configuration File
target_include_directories(common PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           )



            
