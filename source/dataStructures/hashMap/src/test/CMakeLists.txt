enable_testing()

set(GTest_ROOT /usr/src/googletest/googletest)
add_subdirectory(${GTest_ROOT}
        "${CMAKE_CURRENT_BINARY_DIR}/googletest" EXCLUDE_FROM_ALL)


set(TEST_PROJECT_NAME DataStructuresTest)
# Create a variable to contain the source files
set(DATASTRUCTURES_TEST_SRC
TestMain.cpp
)

# Add the subdirectories
add_subdirectory(maps)


# This command tells CMake to create an executable using the specified source code files
add_executable(${TEST_PROJECT_NAME}
            ${DATASTRUCTURES_TEST_SRC}
            )


target_link_libraries(${TEST_PROJECT_NAME}
                    gtest_main
                    mapsTests
                    )

include(GoogleTest)
gtest_discover_tests(
    ${TEST_PROJECT_NAME}
        )
