//
// Created by tom on 9/15/25.
//

#include "headers/FoundTrainer.h"

#include <iostream>
#include <ostream>

#include "headers/Exploration.h"
#include "headers/GameOver.h"

using namespace std;

FoundTrainer::FoundTrainer(StateMachine *stateMachine)
    : AbstractState(stateMachine) {}

void FoundTrainer::state() {
    cout << "FoundTrainer::state" << endl;
    int randomResult = rand() % 2;
    if (randomResult) {
        cout << "Vole de Pokemon" << endl;
        stateMachine->setCurrentState(new Exploration(stateMachine));
    } else {
        stateMachine->setCurrentState(new GameOver(stateMachine));
    }
}
