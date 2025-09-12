//
// Created by tom on 9/11/25.
//

#include "headers/PCPokemon.h"

int PCPokemon::getId() const {
    return id;
}

std::string PCPokemon::getName() const {
    return name;
}

void PCPokemon::addPokemon(const Pokemon &pokemon) {
    this->listPokemon.push_back(pokemon);
}

void PCPokemon::removePokemon(const Pokemon &pokemon) {
    for (int i = 0; i < this->listPokemon.size(); i++) {
        if (this->listPokemon.at(i).getId() == pokemon.getId()) {
            this->listPokemon.erase(this->listPokemon.begin() + i);
        }
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