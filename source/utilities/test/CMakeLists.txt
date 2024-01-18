enable_testing()

# Add the subdirectories
add_subdirectory(error_test)

# Compile Executable
set(GTest_ROOT /usr/src/googletest/googletest)
add_subdirectory(${GTest_ROOT}
        "${CMAKE_CURRENT_BINARY_DIR}/googletest" EXCLUDE_FROM_ALL)


# set(LIBRARY_NAME mapsTests)
set(TEST_PROJECT_NAME UtilitiesTest)

# Create a variable to contain the source files
set(TEST_SRC
    TestMain.cpp
    )


# This command tells CMake to create an executable using the specified source code files
add_executable(${TEST_PROJECT_NAME}
               ${TEST_SRC}
               )

target_link_libraries(${TEST_PROJECT_NAME}
                    gtest_main
                    error_test
                    )

# Link in the Configuration File
target_include_directories(${TEST_PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

include(GoogleTest)
gtest_discover_tests(
    ${TEST_PROJECT_NAME}
    )
