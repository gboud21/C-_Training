enable_testing()

set(GTest_ROOT /usr/src/googletest/googletest)
add_subdirectory(${GTest_ROOT}
        "${CMAKE_CURRENT_BINARY_DIR}/googletest" EXCLUDE_FROM_ALL)


# set(LIBRARY_NAME mapsTests)
set(TEST_PROJECT_NAME MapTest)

# Create a variable to contain the source files
set(MAPS_TEST_SRC
PerfectHashNode-test.cpp
PerfectHashMap-test.cpp
)


# This command tells CMake to create an executable using the specified source code files
add_executable(${TEST_PROJECT_NAME}
            ${MAPS_TEST_SRC}
            )

target_link_libraries(${TEST_PROJECT_NAME}
                    gtest_main
                    perfect_hash_map
                    )

include(GoogleTest)
gtest_discover_tests(
    ${TEST_PROJECT_NAME}
    )

