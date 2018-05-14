cmake_minimum_required(VERSION 3.10)
project(adjacent_cells_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

enable_testing()

find_package(Boost 1.60 COMPONENTS program_options REQUIRED)

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)