# Set the name of the target
set(TARGET_NAME logger)

# Create a variable to contain the header files
set(LOGGER_H
    Logger.h
    )

# Create a variable to contain the source files
set(LOGGER_SRC
    Logger.cpp
    )

# This command tells CMake to create an executable using the specified source code files
add_library(${TARGET_NAME} STATIC
            ${LOGGER_H}
            ${LOGGER_SRC}
            )


target_link_libraries(logger PUBLIC
                    error
                    )

# Link in the Configuration File
target_include_directories(${TARGET_NAME} PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           )


