#include <iostream>
#include "headers/Pokemon.h"

#include "headers/Pokedex.h"


int main() {

    Pokemon Tiplouf(1,"Tiplouf",15,35,15,1);
    Pokemon Salameche(2,"Salameche",15,25,25,1);

    Tiplouf.strike(Salameche);
    Tiplouf.strike(Salameche);

    Pokedex::getInstance()->findByName("Charizard").displayInfo();
    Pokedex * test = Pokedex::getInstance();
    Pokedex * test1 = Pokedex::getInstance();
    Pokedex * test2 = Pokedex::getInstance();
    Pokedex * test3 = Pokedex::getInstance();


    return 0;
}