cmake_minimum_required(VERSION 3.15)
project(WebServer CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# This tells CMake where to look for source files
add_executable(web_server src/main.cpp)