//
// Created by tom on 9/12/25.
//

#include "headers/TeamPokemon.h"

#include <algorithm>

TeamPokemon::TeamPokemon(const std::vector<std::string>& names, PCPokemon& linkedPC): linkedPC(linkedPC) {
    if (names.size() >= MAX_TEAM_SIZE) {
        std::cout << "ERROR : MaxTeamSize = 6" << std::endl;
    }else {
        for (const std::string& name : names) {
            Pokemon found = linkedPC.findByName(name);
            if (found.getId() != -1) {
                this->listPokemon.push_back(found);
                linkedPC.removePokemonFromPC(found);
            } else {
                std::cout << "Pokemon " << name << " not found in PC" << std::endl;
            }
        }
    }
}

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

void TeamPokemon::captureWildPokemon(const Pokemon& pokemon) {
    if (this->listPokemon.size() >= MAX_TEAM_SIZE) {
        linkedPC.addPokemonToPC(pokemon);
        std::cout << "Team is full, " << pokemon.getName() << " was sent to PC!" << std::endl;
    } else {
        this->listPokemon.push_back(pokemon);
        std::cout << pokemon.getName() << " was added to your team!" << std::endl;
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
