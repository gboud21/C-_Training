# Set the name of the target
set(TARGET_NAME enum)


# Create a variable to contain the header files
set(TARGET_H
ExtendableEnum.h
ExtendableEnumLiteral.h
)

# Create a variable to contain the source files
# set(TARGET_SRC
# ExtendableEnum.cpp
# ExtendableEnumLiteral.cpp
# )

# This command tells CMake to create an executable using the specified source code files
add_library(${TARGET_NAME} STATIC
            ${TARGET_H}
            ${TARGET_SRC}
            )

set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# target_link_libraries(${TARGET_NAME} PUBLIC
#                     logger
#                     )

# Link in the Configuration File
target_include_directories(${TARGET_NAME} PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           )


