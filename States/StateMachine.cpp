//
// Created by tom on 9/15/25.
//

#include "headers/StateMachine.h"

#include <iostream>
#include <ostream>

#include "headers/HomeScreen.h"

using namespace std;

AbstractState::AbstractState(StateMachine *stateMachine)
    : stateMachine(stateMachine){}

StateMachine::StateMachine() {
    currentState = new HomeScreen(this);
}

void StateMachine::setCurrentState(AbstractState *abstractState) {
    currentState = abstractState;
}

void StateMachine::state() const {
    currentState->state();
}
