cmake_minimum_required(VERSION 3.13)

# set the project name
project(Flyweight)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set compile options
add_compile_options(-Wall -Wextra -pedantic -Werror)

# add the executable
add_executable(Flyweight flyweight.cpp)
