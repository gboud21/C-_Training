# Set the name of the library
set(TARGET_NAME trees)

# The header files to compile
set(TARGET_H
    BinaryNode.h
    BinaryTree.h
    )

# The source files to compile
# set(TARGET_SRC
#     BinaryNode.cpp
#     BinaryTree.cpp
#     )

add_library(${TARGET_NAME} STATIC
            ${TARGET_H}
            # ${TARGET_SRC}
            )


target_include_directories(${TARGET_NAME} PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}")

# Set Target Language to C++
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)