//
// Created by tom on 9/15/25.
//

#ifndef TP1_STATEMACHINE_H
#define TP1_STATEMACHINE_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../Pokemon/headers/TeamPokemon.h"



class StateMachine;

class AbstractState {
protected:
    StateMachine *stateMachine;
    AbstractState(StateMachine *stateMachine);
public:
    virtual ~AbstractState() = default;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    virtual void handleEvent(const sf::Event &event) = 0;
};

class StateMachine {
private:
    TeamPokemon playerTeam;
    PCPokemon playerPC;


    AbstractState *currentState;
    bool gameOver = false;

    sf::RenderWindow &window;
public:
    StateMachine(sf::RenderWindow &win, int id, std::string pcName);

    [[nodiscard]] AbstractState *getCurrentState() const{ return currentState; }
    [[nodiscard]] sf::RenderWindow &getWindow() const{ return window; }
    TeamPokemon &getPlayerTeam(){ return playerTeam; }
    PCPokemon &getPlayerPC(){ return playerPC; }

    void setCurrentState(AbstractState *currentState);

    [[nodiscard]] bool isGameOver() const;

    void handleEvent(const sf::Event &event) {
        if (currentState) {
            currentState->handleEvent(event);
        }
    }

    void update() const;
    void render() const;
};

#endif //TP1_STATEMACHINE_H