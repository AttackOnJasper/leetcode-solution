cmake_minimum_required(VERSION 3.6)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    leetcode/header.hpp
    leetcode/main.cpp
    leetcode/MediumQuestions.cpp)

add_executable(leetcode ${SOURCE_FILES})