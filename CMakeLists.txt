cmake_minimum_required(VERSION 3.26)
project(340project)

set(CMAKE_CXX_STANDARD 17)

add_executable(340project main.cpp
        room.h
        building.cpp
        clerk.cpp
        floor.cpp
        guest.cpp
        linkedlist.cpp
        node.cpp
        person.cpp
        room.cpp
        elevator.cpp)
