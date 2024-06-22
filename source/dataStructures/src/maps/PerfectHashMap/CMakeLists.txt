# Set the C++ Standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(TARGET_NAME PERFECTHASHMAP)
set(LIB_NAME perfect_hash_map)
# Create a variable to contain the source files
set(HEADERS
PerfectHashMap.h
PerfectHashNode.h
)

# Create a variable to contain the source files
# set(SRC
# PerfectHashMap.cpp
# PerfectHashNode.cpp
# )

# This command tells CMake to create an executable using the specified source code files
add_library(${LIB_NAME} STATIC
            ${HEADERS}
            # ${SRC}
            )


# target_link_libraries(pointers PUBLIC
#                     common
#                     )

# Link in the Configuration File
target_include_directories(${LIB_NAME} PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           )

set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

