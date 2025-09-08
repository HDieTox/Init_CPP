//
// Created by tom on 9/8/25.
//

#ifndef TEST_SETOFPOKEMON_H
#define TEST_SETOFPOKEMON_H

#include <vector>
#include <iostream>
#include <string>

#include "Pokemon.h"

class SetOfPokemon {
protected:

    std::vector<Pokemon> listPokemon;

public:
    Pokemon findByIndex(int index) const;
    Pokemon findByName(std::string name) const ;

    void printList() const;

    virtual ~SetOfPokemon();
};


#endif //TEST_SETOFPOKEMON_H