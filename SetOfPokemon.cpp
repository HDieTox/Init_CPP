//
// Created by tom on 9/8/25.
//

#include "headers/SetOfPokemon.h"

void SetOfPokemon::printList() const {
    for (size_t i = 0; i < listPokemon.size(); ++i) {
        std::cout << i << " | " << listPokemon.at(i).getName() << std::endl;
    }
}