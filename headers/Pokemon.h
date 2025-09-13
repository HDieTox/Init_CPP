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
    bool isAlive;

    double critChance =  0.40;
    int critDamage = 2;
public:
    Pokemon(const int id, const std::string name, const double hp, const double attack, const double defense, const int generation)
    : id(id), name(name), hp(hp), attack(attack), defense(defense), generation(generation) {
        countPokemon++;
        isAlive = true;
    }

    Pokemon(const Pokemon &basePokemon):
    id(basePokemon.id), name(basePokemon.name), hp(basePokemon.hp), attack(basePokemon.attack), defense(basePokemon.defense), generation(basePokemon.generation) {
        countPokemon++;
        isAlive = basePokemon.isAlive;
    }

    Pokemon(const int id) : name("NULL"), hp(-1), attack(-1), defense(-1), generation(-1) {
        this->id = id;
    }

    [[nodiscard]] double crit_chance() const {return critChance;}

    [[nodiscard]] int crit_damage() const {return critDamage;}

    [[nodiscard]] double getHP() const;
    [[nodiscard]] double getAttack() const;
    [[nodiscard]] double getDefense() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getId() const;
    bool getAlive() const;

    void setHP(const double &newHP);

    void displayInfo() const;
    void strike(Pokemon &target) const;

    void sometimesCriticalStrike(Pokemon &target) const;

    ~Pokemon() {
        countPokemon--;
    }

};

#endif // POKEMON_H
