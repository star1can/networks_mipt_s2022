cmake_minimum_required(VERSION 3.17)
project(task2)
include_directories(../lib)

set(CMAKE_CXX_STANDARD 17)

add_executable(task2 main.cpp ../lib/graph.cpp ../lib/graph.hpp ../lib/matrix_graph.hpp ../lib/matrix_graph.cpp)

