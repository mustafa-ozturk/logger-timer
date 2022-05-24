cmake_minimum_required(VERSION 3.22)
project(mentee)

include_directories(include)

set(CMAKE_CXX_STANDARD 17)

add_executable(mentee src/main.cpp src/Logger.cpp src/Timer.cpp)
