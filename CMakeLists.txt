cmake_minimum_required(VERSION 3.14)
project(DummyClient)

set(CMAKE_CXX_STANDARD 11)

add_executable(DummyClient clientmain.cpp commonSocket.cpp commonSocket.h clientProtocol.cpp clientProtocol.h clientClient.cpp clientClient.h commonClosedSocket.h)