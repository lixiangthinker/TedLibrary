cmake_minimum_required(VERSION 3.16)
project(TedLibrary)

set(CMAKE_CXX_STANDARD 14)

add_executable(TedLibrary main.cpp TedString.cpp TedString.h)