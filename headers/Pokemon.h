#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

class Pokemon {
    private:

    static int countPokemon;

    int id;
    std::string name;
    double hp;
    double attack;
    double defense;
    int generation;

public:
    Pokemon(const int id, const std::string name, const double hp, const double attack, const double defense, const int generation)
    : id(id), name(name), hp(hp), attack(attack), defense(defense), generation(generation) {
        countPokemon++;
    }

    Pokemon(const Pokemon &basePokemon):
    id(basePokemon.id), name(basePokemon.name), hp(basePokemon.hp), attack(basePokemon.attack), defense(basePokemon.defense), generation(basePokemon.generation) {
        countPokemon++;
    }

    double getHP() const;
    double getAttack() const;
    double getDefense() const;
    std::string getName() const;

    void setHP(const double &newHP);

    void displayInfo() const;
    void strike(Pokemon &target) const;

    ~Pokemon() {
        countPokemon--;
    }

};

#endif // POKEMON_H
