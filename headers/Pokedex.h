//
// Created by tom on 9/8/25.
//

#ifndef TP1_POKEDEX_H
#define TP1_POKEDEX_H
#include <format>
#include <string>
#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <vector>

#include "SetOfPokemon.h"


class Pokedex : public SetOfPokemon {
private:
    std::string path_to_pokedex="";
    Pokedex(const std::string &path_to_pokedex) ;
    static Pokedex *pinstance;
    ~Pokedex();

public:
    static Pokedex* getInstance();

   // Pokemon findByIndex(int index) const;
   // Pokemon findByName(std::string name) const;

};

#endif //TP1_POKEDEX_H