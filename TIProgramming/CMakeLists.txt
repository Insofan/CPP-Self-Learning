cmake_minimum_required(VERSION 3.10)
project(TIProgramming)

set(CMAKE_CXX_STANDARD 98)

add_executable(TIProgramming main.cpp)
add_executable(testSeq testSeq.cpp)

add_executable(02addr 02addr.cpp)

add_executable(eco_ser echo/echoSer.cpp
        )
add_executable(eco_cli echo/echoCli.cpp)
add_executable(echoSer2 echo2/echoSer2.cpp)
add_executable(echoCli2 echo2/echoCli2.cpp)
add_executable(p2pSer p2p/p2pSer.cpp)
add_executable(p2pCli p2p/p2pCli.cpp)

add_executable(testCli p2p/testCli.cpp)
add_executable(testServ p2p/testServ.cpp)
add_executable(packageSer1 package1/packageSer1.cpp)
add_executable(packageCli1 package1/packageCli1.cpp)