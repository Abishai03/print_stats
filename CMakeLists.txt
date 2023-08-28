cmake_minimum_required(VERSION 3.10)

project(print_stats)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/inc)

add_executable(print_stats src/main.cpp src/csv_parser.cpp src/stats.cpp)

include_directories(${CMAKE_SOURCE_DIR}/src)
