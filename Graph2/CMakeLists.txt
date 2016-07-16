cmake_minimum_required(VERSION 3.3)
project(Graph2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c grafo.h grafo.c main.c main.c)
add_executable(Graph2 ${SOURCE_FILES} main.c)