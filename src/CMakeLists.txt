cmake_minimum_required(VERSION 3.22)
project(20_1_write_to_statement)

set(CMAKE_CXX_STANDARD 14)
set (MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(20_1_write_to_statement main.cpp date_checker.cpp ${MY_INCLUDE_DIR}/date_checker.h)
target_link_directories(20_1_write_to_statement PUBLIC ${MY_INCLUDE_DIR})