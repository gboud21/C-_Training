set(TARGET_NAME leet_21_test)

# Create a variable to contain the source files
set(PROBLEM_SRC
    MergeTwoSortedLists-test.cpp
    )


# This command tells CMake to create an executable using the specified source code files
add_library(${TARGET_NAME}
            ${PROBLEM_SRC}
            )

target_link_libraries(${TARGET_NAME}
                    gtest_main
                    leet_21
                    )

target_include_directories(${TARGET_NAME} PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}")
