enable_testing()

set(GTest_ROOT /usr/src/googletest/googletest)
add_subdirectory(${GTest_ROOT}
        "${CMAKE_CURRENT_BINARY_DIR}/googletest" EXCLUDE_FROM_ALL)

# Create a variable to contain the source files
set(POINTERS_TEST_SRC
BasicClass-test.cpp
)

# This command tells CMake to create an executable using the specified source code files
add_executable(PointersTest
            ${POINTERS_TEST_SRC}
            )


target_link_libraries(PointersTest
                    gtest_main
                    pointers
                    )

include(GoogleTest)
gtest_discover_tests(
    PointersTest
        )
