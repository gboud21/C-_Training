set(TARGET_NAME trees_test)

# Create a variable to contain the source files
set(TARGET_SRC
    BinaryNode-test.cpp
    )


# This command tells CMake to create an executable using the specified source code files
add_library(${TARGET_NAME}
            ${TARGET_SRC}
            )

target_link_libraries(${TARGET_NAME}
                    gtest_main
                    trees
                    )

target_include_directories(${TARGET_NAME} PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}")
