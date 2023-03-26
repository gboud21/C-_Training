# Create a variable to contain the source files
set(RAW_DATA_H
    RawDataBuffer.h
    RawDataStream.h
    )

# Create a variable to contain the source files
set(RAW_DATA_SRC
    RawDataBuffer.cpp
    RawDataStream.cpp
    )

# This command tells CMake to create an executable using the specified source code files
add_library(rawData STATIC
            ${RAW_DATA_H}
            ${RAW_DATA_SRC}
            )

# Link in the Configuration File
target_include_directories(rawData PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           )



            
