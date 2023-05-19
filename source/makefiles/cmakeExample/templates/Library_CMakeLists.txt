# Create a variable to contain the source files
set(POINTERS_H
BasicClass.h
ConstantClass.h
)

# Create a variable to contain the source files
set(POINTERS_SRC
BasicClass.cpp
ConstantClass.cpp
)

# This command tells CMake to create an executable using the specified source code files
add_library(pointers STATIC
            ${POINTERS_H}
            ${POINTERS_SRC}
            )


# target_link_libraries(pointers PUBLIC
#                     common
#                     )

# Link in the Configuration File
target_include_directories(pointers PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           )


