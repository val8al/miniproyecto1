cmake_minimum_required(VERSION 3.14)
project(miniproyecto1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")
set(OpenGLinkers -lglut -lGLU -lGL curses)

add_executable(miniproyecto1 main.cpp)
target_link_libraries(miniproyecto1 ${OpenGLinkers} m)