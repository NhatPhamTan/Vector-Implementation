cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(Vector LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src/main)
#add_subdirectory(include)