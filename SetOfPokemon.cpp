//
// Created by tom on 9/8/25.
//

#include "headers/SetOfPokemon.h"

void SetOfPokemon::printList() const {
    for (size_t i = 0; i < listPokemon.size(); ++i) {
        std::cout << i << " | " << listPokemon.at(i).getName() << std::endl;
    }
}

Pokemon SetOfPokemon::findByIndex(int index) const {
    return Pokemon(listPokemon.at(index));
}



Pokemon SetOfPokemon::findByName(const std::string& name) const {
    for (Pokemon poke : listPokemon) {
        if (poke.getName() == name)
            return Pokemon(poke);
    }
    throw std::invalid_argument(name + " : Pokemon does not exist");
}

SetOfPokemon::~SetOfPokemon() {

}