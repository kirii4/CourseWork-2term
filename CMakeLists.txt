cmake_minimum_required(VERSION 3.20)
project(Challenge)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Challenge
        acc_menu.cpp
        acc_menu.h
        account.cpp
        account.h
        check.cpp
        check.h
        file.cpp
        file.h
        Libraries.h
        list.cpp
        list.h
        main.cpp
        print.cpp
        print.h
        sort.cpp
        sort.h
        struct.h)
