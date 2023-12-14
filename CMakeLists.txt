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

add_executable(td2_exo1
        td2/exo1/search_main.cpp
        td2/exo1/SearchingAlgorithm.h
        td2/exo1/SearchingAlgorithm.cpp
        td2/exo1/LinearSearch.cpp
        td2/exo1/LinearSearch.h
        td2/exo1/JumpSearch.cpp
        td2/exo1/JumpSearch.h
        td2/exo1/BinarySearch.cpp
        td2/exo1/BinarySearch.h
)
add_executable(td2_exo2
        td2/exo2/matrix_main.cpp
        td2/exo2/matrix.h
        td2/exo2/num_matrix.h
)

add_executable(td3_exo1
        td3/exo1/main.cpp
)

add_executable(td3_exo2
        td3/exo2/main.cpp
)

add_executable(td3_exo3
        td3/exo3/main.cpp
)

add_executable(td4_pokemon
        td4-pokemon/main.cpp
        td4-pokemon/headers/pokemon_card.h
        td4-pokemon/pokemon_card.cpp
        td4-pokemon/headers/card.h
        td4-pokemon/card.cpp
        td4-pokemon/headers/trainer_card.h
        td4-pokemon/trainer_card.cpp
        td4-pokemon/main.cpp
        td4-pokemon/headers/player.h
        td4-pokemon/player.cpp
        td4-pokemon/player.cpp
)
