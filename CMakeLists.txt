cmake_minimum_required(VERSION 4.0)
project(tp1)

set(CMAKE_CXX_STANDARD 20)


add_executable(tp1 main.cpp
        Pokemon.cpp
        headers/Pokemon.h
        SetOfPokemon.cpp
        headers/SetOfPokemon.h
        Pokedex.cpp
        headers/Pokedex.h)

target_link_libraries(tp1
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)
