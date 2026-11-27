cmake_minimum_required(VERSION 3.23) # CMake version for this project

project(minishell LANGUAGES CXX) # Name of the project and the programming language used


# Set C++ standard to use filesystem
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Ensure that the specified C++ standard is required
set(CMAKE_CXX_EXTENSIONS OFF) # Disable compiler-specific extensions

add_executable(minishell) # name of the executable to be built

target_sources(minishell # name of the executable to which the sources are being added
        # the sources are private to the target and not intended
        # to be used by other targets and here the source files are specified
    PRIVATE 
        src/main.cpp
        src/inputParser.cpp
        src/execute.cpp

        # for the header files, we can use the FILE_SET command to specify the base 
        # directory and the header files to be included in the target
    PRIVATE 
        FILE_SET HEADERS
        BASE_DIRS src
        FILES
            src/inputParser.h
            src/execute.h
)