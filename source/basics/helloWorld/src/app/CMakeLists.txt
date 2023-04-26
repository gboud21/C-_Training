# Create a variable to contain the source files
set(APP_SRC
    pandasFirstApp.cpp)

# This command tells CMake to create an executable using the specified source code files
add_executable(${PROJECT_NAME} 
               ${APP_SRC}
               )

# Link in the Configuration File
target_include_directories(${PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )



