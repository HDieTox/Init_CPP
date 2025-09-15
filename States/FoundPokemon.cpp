//
// Created by tom on 9/15/25.
//

#include "headers/FoundPokemon.h"

#include <iostream>
#include <ostream>

#include "headers/Exploration.h"

using namespace std;

FoundPokemon::FoundPokemon(StateMachine *stateMachine)
    : AbstractState(stateMachine) {}

void FoundPokemon::state() {
    cout << "Found Pokemon" << endl;
    int randomResult = rand() % 2;
    if (randomResult) {
        cout << "Pokemon captured" << endl;
        stateMachine->setCurrentState(new Exploration(stateMachine));
    } else {
        cout << "Pokemon NOT captured" << endl;
        stateMachine->setCurrentState(new Exploration(stateMachine));
    }
}
