set(TARGET_NAME leet_4_test)

# Create a variable to contain the source files
set(PROBLEM_SRC
    MedianTwoSortedArrays-test.cpp
    )


# This command tells CMake to create an executable using the specified source code files
add_library(${TARGET_NAME}
            ${PROBLEM_SRC}
            )

target_link_libraries(${TARGET_NAME}
                    gtest_main
                    leet_4
                    )

target_include_directories(${TARGET_NAME} PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}")
