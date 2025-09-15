//
// Created by tom on 9/15/25.
//

#include "headers/Exploration.h"

#include <iostream>
#include <ostream>
#include <unistd.h>

#include "headers/FoundPokemon.h"
#include "headers/FoundTrainer.h"

using namespace std;

Exploration::Exploration(StateMachine *stateMachine)
    : AbstractState(stateMachine) {}

void Exploration::state() {
    cout << "Exploration::state" << endl;
    int randomDelay = rand() % 5;
    sleep(randomDelay);
    int randomFind = rand() % 2;
    if (randomFind) {
        stateMachine->setCurrentState(new FoundPokemon(stateMachine));
    } else {
        stateMachine->setCurrentState(new FoundTrainer(stateMachine));
    }
}

