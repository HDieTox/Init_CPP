//
// Created by tom on 9/15/25.
//

#include "headers/HomeScreen.h"

#include <iostream>
#include <ostream>

#include "headers/Exploration.h"

using namespace std;

HomeScreen::HomeScreen(StateMachine *stateMachine)
    : AbstractState(stateMachine){}

void HomeScreen::state() {
    cout << "Home Screen" << endl;
    stateMachine->setCurrentState(new Exploration(stateMachine));
}