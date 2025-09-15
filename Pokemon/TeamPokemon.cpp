//
// Created by tom on 9/12/25.
//

#include "headers/TeamPokemon.h"

#include <algorithm>

void TeamPokemon::addPokemonToTeam(const Pokemon &pokemon) {
    if (this->listPokemon.size() >= MAX_TEAM_SIZE) {
        std::cout << "ERROR : Team is full" << std::endl;
        return;
    }
    Pokemon found = linkedPC.findByName(pokemon.getName());
    this->listPokemon.push_back(found);
    linkedPC.removePokemonFromPC(found);
}


void TeamPokemon::removePokemonFromTeam(const Pokemon &pToRemove, PCPokemon &PCDest) {
    auto index = std::ranges::find_if(
        this->listPokemon.begin(), this->listPokemon.end(),
        [&pToRemove](const Pokemon &p) { return pToRemove.getId() == p.getId(); }
    );

    if (index != this->listPokemon.end()) {
        PCDest.addPokemonToPC(*index);
        this->listPokemon.erase(index);
    } else {
        std::cout << "ERROR : Pokemon not found in Team" << std::endl;
    }
}


void TeamPokemon::displayTeam() const{
    std::cout << "Team Display : Linked PC : " << this->linkedPC.getName() << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    for (const Pokemon& poke : this->listPokemon) {
        poke.displayInfo();
    }
    std::cout << "----------------------------------------" << std::endl;
}
