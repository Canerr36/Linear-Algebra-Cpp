cmake_minimum_required(VERSION 3.10)

project(LinearAlgebraCpp
    VERSION 0.3
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(matrix_example
    examples/main.cpp
)

target_include_directories(matrix_example
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
