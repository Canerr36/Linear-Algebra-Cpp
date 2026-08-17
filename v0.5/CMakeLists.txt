cmake_minimum_required(VERSION 3.10)

project(LinearAlgebraCpp
    VERSION 0.5
    LANGUAGES CXX
)

add_executable(matrix_example
    examples/main.cpp
)

target_include_directories(matrix_example
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(matrix_example PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
