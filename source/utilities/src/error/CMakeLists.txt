# Set the name of the target
set(TARGET_NAME error)

# Create a variable to contain the header files
set(ERROR_H
    ErrorHandler.h
    )

# Create a variable to contain the source files
set(ERROR_SRC
    ErrorHandler.cpp
    )

# This command tells CMake to create an executable using the specified source code files
add_library(error STATIC
            ${ERROR_H}
            ${ERROR_SRC}
            )


target_link_libraries(error PUBLIC
                    logger
                    )

# Link in the Configuration File
target_include_directories(error PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           )


