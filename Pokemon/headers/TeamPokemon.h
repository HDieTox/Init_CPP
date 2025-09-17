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
    TeamPokemon(const std::vector<std::string>& names, PCPokemon& linkedPC);

    void addPokemonToTeam(const Pokemon &pokemon);
    void removePokemonFromTeam(const Pokemon &pToRemove, PCPokemon &PCDest);
    void captureWildPokemon(const Pokemon& pokemon);


    void displayTeam() const;
};


#endif //TP1_TEAMPOKEMON_H