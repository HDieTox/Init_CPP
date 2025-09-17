//
// Created by tom on 9/15/25.
//

#include "headers/StateMachine.h"

#include <iostream>
#include <ostream>

#include "headers/GameOver.h"
#include "headers/HomeScreen.h"

using namespace std;

AbstractState::AbstractState(StateMachine *stateMachine)
    : stateMachine(stateMachine){}

StateMachine::StateMachine(sf::RenderWindow &win, int id, std::string pcName) : playerTeam({},playerPC), playerPC(id,pcName), window(win) {
    currentState = new HomeScreen(this);
}

void StateMachine::setCurrentState(AbstractState *newState) {
    if (currentState != nullptr) {
        delete currentState;
    }
    currentState = newState;
    if (dynamic_cast<GameOver*>(newState)) {
        cout << "Game Over" << endl;
        gameOver = true;
    }
}

bool StateMachine::isGameOver() const {
    if (gameOver) return true;
    return false;
}

void StateMachine::update() const {
    currentState->update();
}

void StateMachine::render() const {
    currentState->render(window);
}
