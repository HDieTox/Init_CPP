//
// Created by tom on 9/12/25.
//

#ifndef TP1_TEAMPOKEMON_H
#define TP1_TEAMPOKEMON_H
#include "PCPokemon.h"
#include "Pokemon.h"
#include "SetOfPokemon.h"


class TeamPokemon : public SetOfPokemon {
private:
    PCPokemon& linkedPC;
    static constexpr int MAX_TEAM_SIZE = 6;

public:
    TeamPokemon(const std::vector<std::string>& names, PCPokemon& linkedPC): linkedPC(linkedPC) {
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
    };

    void addPokemonToTeam(const Pokemon &pokemon);
    void removePokemonFromTeam(const Pokemon &pToRemove, PCPokemon &PCDest);

    void displayTeam() const;
};


#endif //TP1_TEAMPOKEMON_H