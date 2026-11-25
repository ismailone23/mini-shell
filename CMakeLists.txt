cmake_minimum_required(VERSION 3.23)

project(minishell LANGUAGES CXX)

add_executable(minishell)

target_sources(minishell
    PRIVATE
        src/main.cpp
        src/inputParser.cpp

    PRIVATE
        FILE_SET HEADERS
        BASE_DIRS src
        FILES
            src/inputParser.h
)