cmake_minimum_required(VERSION 3.26)
project(ecole_cpp_f)

set(CMAKE_CXX_STANDARD 23)

add_executable(EXO1 exo1/main.cpp
        exo1/main.h
        exo1/my_class.cpp
        exo1/my_class.h)

add_executable(
        EXO2 exo2/main.cpp
        exo2/Complex2D.cpp
        exo2/Complex2D.h
)