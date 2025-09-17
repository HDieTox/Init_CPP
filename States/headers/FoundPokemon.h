#ifndef TP1_FOUNDPOKEMON_H
#define TP1_FOUNDPOKEMON_H

#include "StateMachine.h"
#include "../../Pokemon/headers/Pokedex.h"
#include "../../Pokemon/headers/Pokemon.h"

class FoundPokemon : public AbstractState {
private:
    Pokemon wildPokemon;
    sf::Font font;
    sf::Text encounterText1;
    sf::Text encounterText2;
    sf::Text optionText;
    sf::RectangleShape captureButton;
    sf::RectangleShape fleeButton;
    sf::Text captureText;
    sf::Text fleeText;

public:
    FoundPokemon(StateMachine *stateMachine, const Pokemon& pokemon);
    void update() override;
    void render(sf::RenderWindow &window) override;
    void handleEvent(const sf::Event& event) override;

     ~FoundPokemon() override = default;
};

#endif