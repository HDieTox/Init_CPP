#include <iostream>

#include "headers/PCPokemon.h"
#include "headers/Pokemon.h"

#include "headers/Pokedex.h"


int main() {

    Pokemon Tiplouf(1,"Tiplouf",15,35,15,1);
    Pokemon Salameche(2,"Salameche",15,25,25,1);
    Pokemon Mewtwo(150,"Mewtwo",106,110,90,1);
    Tiplouf.strike(Salameche);
    Tiplouf.strike(Salameche);
    Mewtwo.sometimesCriticalStrike(Tiplouf);

    PCPokemon BoiteTom(1,"PC de Tom");
    PCPokemon BoiteMael(2,"PC de Mael");


    BoiteTom.addPokemon(Pokedex::getInstance()->findByName("Charizard"));
    BoiteTom.addPokemon(Pokedex::getInstance()->findByName("Charmander"));
    BoiteTom.displayPC();

    BoiteTom.removePokemon(Pokedex::getInstance()->findByName("Charizard"));
    BoiteTom.displayPC();

    return 0;
}