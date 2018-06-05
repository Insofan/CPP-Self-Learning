cmake_minimum_required(VERSION 3.10)
project(TIProgramming)

set(CMAKE_CXX_STANDARD 98)

add_executable(TIProgramming main.cpp)
add_executable(main main.cpp)
add_executable(testSeq testSeq.cpp)

add_executable(02addr 02addr.cpp)

add_executable(eco_ser echo/echoSer.cpp
        )
add_executable(eco_cli echo/echoCli.cpp)
add_executable(echoSer2 echo2/echoSer2.cpp)
add_executable(echoCli2 echo2/echoCli2.cpp)