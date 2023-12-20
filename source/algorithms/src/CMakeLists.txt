# Set the name of the library
set(TARGET_NAME common)

# The header files to be compiled
set(COMMON_H
    AlgorithmTypes.h
    )

# Create the library
add_library(${TARGET_NAME} STATIC
            ${COMMON_H}
            )

set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Add the include directories to the library
target_include_directories(${TARGET_NAME} PUBLIC
                          "${CMAKE_CURRENT_SOURCE_DIR}"
                          )

# Compile Leet Code Projects
add_subdirectory(leetCode)