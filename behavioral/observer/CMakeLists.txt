cmake_minimum_required(VERSION 3.13)

# set the project name
project(Observer)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(Observer observer.cpp)
