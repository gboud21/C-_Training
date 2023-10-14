enable_testing()

# set(GTest_ROOT /usr/src/googletest/googletest)
# add_subdirectory(${GTest_ROOT}
#         "${CMAKE_CURRENT_BINARY_DIR}/googletest" EXCLUDE_FROM_ALL)


set(LIBRARY_NAME mapsTests)

# Create a variable to contain the source files
set(MAPS_TEST_SRC
StaticMap-test.cpp
StaticNode-test.cpp
Joy2Bin-test.cpp
Joy2Map-test.cpp
)


# This command tells CMake to create an executable using the specified source code files
add_library(${LIBRARY_NAME}
            ${MAPS_TEST_SRC}
            )

target_link_libraries(${LIBRARY_NAME}
                    gtest_main
                    static_maps
                    joy2
                    )

include(GoogleTest)
# gtest_discover_tests(
#     PointersTest
#         )
