//
// Created by tom on 9/15/25.
//

#include "headers/GameOver.h"

#include <iostream>

using namespace std;

GameOver::GameOver(StateMachine *stateMachine)
    : AbstractState(stateMachine){}

void GameOver::state() {
    cout << "Game Over" << endl;
}

