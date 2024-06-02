cmake_minimum_required(VERSION 3.27)
project(tasma)

set(CMAKE_CXX_STANDARD 23)

add_executable(tasma main.cpp
        Operacja.cpp
        Operacja.h
        Zadanie.cpp
        Zadanie.h
        Flowshop.cpp
        Flowshop.h
        Rozwiazanie.cpp
        Rozwiazanie.h
        Procesor.cpp
        Procesor.h)
