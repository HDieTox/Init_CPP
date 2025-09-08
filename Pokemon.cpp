#include "headers/Pokemon.h"

using namespace std;

int Pokemon::countPokemon = 0;

void Pokemon::displayInfo() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "Defense: " << defense << std::endl;
    std::cout << "Generation: " << generation << std::endl;
}

double Pokemon::getHP() const {
    return hp;
}
double Pokemon::getAttack() const {
    return attack;
}
double Pokemon::getDefense() const {
    return defense;
}
string Pokemon::getName() const {
    return name;
}

void Pokemon::setHP(const double &newHP) {
    hp = newHP;
}

void Pokemon::strike(Pokemon &target) const {
    double damageDealt = attack - target.getDefense();
    if (damageDealt > 0) {
        target.setHP(target.getHP() - damageDealt);
    }
    if (target.getHP() <= 0) {
        target.setHP(0);
        cout << "Your " << target.getName() << " is DEAADD" << endl;
    }
}
