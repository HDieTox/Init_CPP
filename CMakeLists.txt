cmake_minimum_required(VERSION 4.0)
project(tp1)

set(CMAKE_CXX_STANDARD 20)


add_executable(tp1 main.cpp
        Pokemon/Pokemon.cpp
        Pokemon/headers/Pokemon.h
        Pokemon/SetOfPokemon.cpp
        Pokemon/headers/SetOfPokemon.h
        Pokemon/Pokedex.cpp
        Pokemon/headers/Pokedex.h
        Pokemon/PCPokemon.cpp
        Pokemon/headers/PCPokemon.h
        Pokemon/TeamPokemon.cpp
        Pokemon/headers/TeamPokemon.h
        States/StateMachine.cpp
        States/headers/StateMachine.h
        States/HomeScreen.cpp
        States/headers/HomeScreen.h
        States/Exploration.cpp
        States/headers/Exploration.h
        States/FoundPokemon.cpp
        States/headers/FoundPokemon.h
        States/FoundTrainer.cpp
        States/headers/FoundTrainer.h
        States/GameOver.cpp
        States/headers/GameOver.h)

    target_link_libraries(tp1
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)
