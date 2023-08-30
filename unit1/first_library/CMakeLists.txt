#define the version of CMake you are using here 3.1
cmake_minimum_required(VERSION 3.1)
#project name
project(first_project)
#C++ version in use, here 17
set(CMAKE_CXX_STANDARD 17)

#created the compile_commands.json file in the src directory. 
#You can get an idea of the compilation process from this file.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#tell CMake where to look for *.hpp ,*.h files
include_directories(include/)

#create library "libfirst", this creates libfirst.a 
add_library(first src/first.cpp)

#add executable main, this creates main.o
add_executable(main src/main.cpp)

#tell the linker to bind these object files together and provide with the final executable
target_link_libraries(main first)