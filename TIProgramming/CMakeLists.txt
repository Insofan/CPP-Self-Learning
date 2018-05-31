cmake_minimum_required(VERSION 3.10)
project(TIProgramming)

set(CMAKE_CXX_STANDARD 98)

add_executable(TIProgramming main.cpp)
add_executable(main main.cpp)
add_executable(testSeq testSeq.cpp)

add_executable(02addr 02addr.cpp)
add_executable(reflect reflect.cpp
        )

add_executable(reflectClient reflectClient.cpp)