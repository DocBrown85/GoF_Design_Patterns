cmake_minimum_required(VERSION 3.13)

# set the project name
project(FactoryMethod)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(FactoryMethod factory_method.cpp)