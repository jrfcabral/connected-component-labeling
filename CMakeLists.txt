cmake_minimum_required(VERSION 3.10)
project(adjacent_cells_cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic -flto")

find_package(Boost 1.40 COMPONENTS program_options REQUIRED)

include_directories(include)

add_executable(adjacent_cells_cpp
        data_handling.cpp
        one_pass.cpp
        main.cpp)
target_link_libraries(adjacent_cells_cpp Boost::program_options)