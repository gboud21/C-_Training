# Set the name of the target
set(TARGET_NAME error)

# Create a variable to contain the header files
set(ERROR_H
ErrorHandler.h
# ExtendableError.h
ErrorTable.h
GenericError.h
)

# Create a variable to contain the source files
set(ERROR_SRC
ErrorHandler.cpp
# ExtendableError.cpp
# ErrorTable.cpp
GenericError.cpp
)

# This command tells CMake to create an executable using the specified source code files
add_library(${TARGET_NAME} STATIC
            ${ERROR_H}
            ${ERROR_SRC}
            )


target_link_libraries(${TARGET_NAME} PUBLIC
                    logger
                    )

# Link in the Configuration File
target_include_directories(${TARGET_NAME} PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           )


