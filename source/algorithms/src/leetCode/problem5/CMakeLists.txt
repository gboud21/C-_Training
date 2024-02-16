# Set the name of the library
set(TARGET_NAME leet_5)

# The header files to compile
set(PROBLEM_H
    LongestPalindromicSubstring.h
    )

# The source files to compile
set(PROBLEM_SRC
LongestPalindromicSubstring.cpp
    )

add_library(${TARGET_NAME} STATIC
            ${PROBLEM_H}
            ${PROBLEM_SRC}
            )

target_link_libraries(${TARGET_NAME}
                      common
                      )

target_include_directories(${TARGET_NAME} PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}")