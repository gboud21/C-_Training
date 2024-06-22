enable_testing()

# Add the subdirectories
add_subdirectory(problem1)
add_subdirectory(problem2)
add_subdirectory(problem3)
add_subdirectory(problem4)
add_subdirectory(problem5)
add_subdirectory(problem13)
add_subdirectory(problem20)
add_subdirectory(problem21)
add_subdirectory(problem121)
add_subdirectory(problem125)
add_subdirectory(problem141)
add_subdirectory(problem226)
add_subdirectory(problem278)
add_subdirectory(problem704)

# Compile Executable
set(GTest_ROOT /usr/src/googletest/googletest)
add_subdirectory(${GTest_ROOT}
        "${CMAKE_CURRENT_BINARY_DIR}/googletest" EXCLUDE_FROM_ALL)


# set(LIBRARY_NAME mapsTests)
set(TEST_PROJECT_NAME LeetCodeTest)

# Create a variable to contain the source files
set(LEET_CODE_SRC
    TestMain.cpp
    )


# This command tells CMake to create an executable using the specified source code files
add_executable(${TEST_PROJECT_NAME}
               ${LEET_CODE_SRC}
               )

target_link_libraries(${TEST_PROJECT_NAME}
                    gtest_main
                    leet_1_test
                    leet_2_test
                    leet_3_test
                    leet_4_test
                    leet_5_test
                    leet_13_test
                    leet_20_test
                    leet_21_test
                    leet_121_test
                    leet_125_test
                    leet_141_test
                    leet_226_test
                    leet_278_test
                    leet_704_test
                    )

# Link in the Configuration File
target_include_directories(${TEST_PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

include(GoogleTest)
gtest_discover_tests(
    ${TEST_PROJECT_NAME}
    )
