//
// Created by tom on 9/11/25.
//

#include "headers/PCPokemon.h"

#include <algorithm>

int PCPokemon::getId() const {
    return id;
}

std::string PCPokemon::getName() const {
    return name;
}

void PCPokemon::addPokemonToPC(const Pokemon &pokemon) {
    this->listPokemon.push_back(pokemon);
}

void PCPokemon::removePokemonFromPC(const Pokemon &pokemon) {
    auto index = std::find_if(
        listPokemon.begin(),
        listPokemon.end(),
        [&](const Pokemon& p) {
            return p.getId() == pokemon.getId();
        }
    );

    if (index != listPokemon.end()) {
        listPokemon.erase(index);
    } else {
        std::cout << "ERROR: Pokemon not found in PC" << std::endl;
    }
}

void PCPokemon::displayPC() const {
    std::cout << "PC ID : " << this->getId() << " | Name : " << this->getName() << std::endl;
    std::cout << "========================================" << std::endl;
    for (Pokemon poke : this->listPokemon) {
        poke.displayInfo();
    }
    std::cout << "========================================" << std::endl;
}