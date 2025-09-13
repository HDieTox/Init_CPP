#include <iostream>

#include "headers/PCPokemon.h"
#include "headers/Pokemon.h"

#include "headers/Pokedex.h"
#include "headers/TeamPokemon.h"


int main() {

    Pokemon Tiplouf(1,"Tiplouf",15,35,15,1);
    Pokemon Salameche(2,"Salameche",15,25,25,1);
    Pokemon Mewtwo(150,"Mewtwo",106,110,90,1);
    Tiplouf.strike(Salameche);
    Tiplouf.strike(Salameche);
    Mewtwo.sometimesCriticalStrike(Tiplouf);

    PCPokemon BoiteTom(1,"PC de Tom");

    BoiteTom.addPokemonToPC(Pokedex::getInstance()->findByName("Charizard"));
    BoiteTom.addPokemonToPC(Pokedex::getInstance()->findByName("Charmander"));
    BoiteTom.displayPC();

    const std::vector<std::string> maTeam = {"Charmander", "Charmeleon"};
    TeamPokemon TeamTom(maTeam, BoiteTom);

    std::cout << "Team créé : " << std::endl;
    TeamTom.displayTeam();

    TeamTom.addPokemonToTeam(BoiteTom.findByName("Charizard"));

    std::cout << "Charizard recup : " << std::endl;
    TeamTom.displayTeam();
    BoiteTom.displayPC();


    TeamTom.removePokemonFromTeam(TeamTom.findByName("Charmander"), BoiteTom);

    std::cout << "Charmander déposé : " << std::endl;
    TeamTom.displayTeam();
    BoiteTom.displayPC();



    return 0;
}
