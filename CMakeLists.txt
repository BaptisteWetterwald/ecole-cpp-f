cmake_minimum_required(VERSION 3.13)
project(ecole_cpp_f)
set(CMAKE_CXX_STANDARD 20)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(td1_exo2
        td1/exo2/Complex2D.cpp
        td1/exo2/Complex2D.h
        td1/exo2/Main.cpp
)

add_executable(td1_exo1
        td1/exo1/main.h
        td1/exo1/main.cpp
        td1/exo1/my_class.cpp
        td1/exo1/my_class.h
)