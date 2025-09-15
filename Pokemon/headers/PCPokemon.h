//
// Created by tom on 9/11/25.
//

#ifndef TP1_PCPOKEMON_H
#define TP1_PCPOKEMON_H
#include "SetOfPokemon.h"


class PCPokemon : public SetOfPokemon {
private:
    int id;
    std::string name;


public:
    PCPokemon(const int id, const std::string &name): id(id), name(name) {}

    int getId() const;
    std::string getName() const;

    void addPokemonToPC(const Pokemon &pokemon);
    void removePokemonFromPC(const Pokemon &pokemon);

    void displayPC() const;
};


#endif //TP1_PCPOKEMON_H