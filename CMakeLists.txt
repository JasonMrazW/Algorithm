cmake_minimum_required(VERSION 3.20)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm main.cpp array/TwoSum.cpp array/TwoSum.h common.h array/RemoveNum.cpp array/RemoveNum.h string/StringExecutor.cpp string/StringExecutor.h)
