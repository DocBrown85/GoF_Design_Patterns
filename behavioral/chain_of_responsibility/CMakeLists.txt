cmake_minimum_required(VERSION 3.13)

# set the project name
project(ChainOfResponsibility)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(ChainOfResponsibility chain_of_responsibility.cpp)
