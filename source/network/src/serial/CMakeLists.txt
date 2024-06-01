# Set the name of the target
set(TARGET_NAME network_serial)

# Create a variable to contain the header files
set(TARGET_H
    SerialDevice.h
    )

# Create a variable to contain the source files
set(TARGET_SRC
    SerialDevice.cpp
    )

# This command tells CMake to create an executable using the specified source code files
add_library(${TARGET_NAME} STATIC
            ${TARGET_H}
            ${TARGET_SRC}
            )


# target_link_libraries(${TARGET_NAME} PUBLIC
#                     )

# Link in the Configuration File
target_include_directories(${TARGET_NAME} PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           )


