## -----------------------------------------------------------------------------
##  C++ Intro | CMakeLists.txt
##
##
## -----------------------------------------------------------------------------

##
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

## Set the project name and version
project(CPP_INTRO VERSION 1.0)

## Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(0-scope 0-scope.cpp)
