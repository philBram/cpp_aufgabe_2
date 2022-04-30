cmake_minimum_required(VERSION 3.21)
project(Versuch_2)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(dishlib)
include_directories(dishlib)

add_executable(Versuch_2 main.cpp A.cpp A.h Customer.cpp Customer.h)
target_link_libraries(Versuch_2 dishlib)
