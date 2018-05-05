cmake_minimum_required(VERSION 3.10)
project(adjacent_cells_cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

include_directories(.)

add_executable(adjacent_cells_cpp
        json.hpp
        main.cpp)
