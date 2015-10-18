cmake_minimum_required(VERSION 3.3)
project(Cartomatic)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static-libgcc -static-libstdc++")

set(SOURCE_FILES
        src/main/cpp/DBAccess.cpp
        src/main/cpp/main.cpp
        src/main/cpp/sqlite3.c
        src/main/cpp/product.cpp
        src/main/cpp/Deposit.cpp
        src/main/cpp/CommandlineIO.cpp)

add_executable(Cartomatic ${SOURCE_FILES})