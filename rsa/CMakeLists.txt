cmake_minimum_required(VERSION 3.29)
project(rsa)

set(CMAKE_CXX_STANDARD 14)

add_executable(rsa
    main.cpp
        rsa.h
        rsa.cpp
        functions.h
        functions.cpp)
