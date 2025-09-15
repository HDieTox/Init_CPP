#include "headers/Pokemon.h"

using namespace std;


int Pokemon::countPokemon = 0;

void Pokemon::displayInfo() const {
    cout << "........................................" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "HP: " << hp << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Generation: " << generation << endl;
    cout << "........................................" << endl;
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

int Pokemon::getId() const {
    return id;
}

bool Pokemon::getAlive() const {
    return isAlive;
}

void Pokemon::setHP(const double &newHP) {
    hp = newHP;
}


void Pokemon::strike(Pokemon &target) const {
    if (isAlive) {
        double damageDealt = attack - target.getDefense();
        if (damageDealt > 0) {
            target.setHP(target.getHP() - damageDealt);
        }
        if (target.getHP() <= 0) {
            target.setHP(0);
            cout << "Your " << target.getName() << " is DEAADD" << endl;
            target.isAlive = false;
        }
    }else {
        cout << target.getName() << " is already DEAADD" << endl;
    }
}

void Pokemon::sometimesCriticalStrike(Pokemon &target) const {
    if (random()<critChance) {
            cout<< "critical strike" << endl;
            strike(target);
            strike(target);
        }else{
        strike(target);
    }
}
