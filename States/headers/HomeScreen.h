//
// Created by tom on 9/15/25.
//

#ifndef TP1_HOMESCREEN_H
#define TP1_HOMESCREEN_H
#include <SFML/Graphics.hpp>

#include "StateMachine.h"


class HomeScreen : public AbstractState{
private:
    bool gameStarted = false;

    sf::Texture logoTexture;
    sf::Sprite logoSprite;

    sf::Font font;
    sf::Text buttonText;
    sf::RectangleShape button;
public:
    HomeScreen(StateMachine *stateMachine);
    void update() override;
    void render(sf::RenderWindow &window) override;

    void handleEvent(const sf::Event &event) override;

    ~HomeScreen() override = default;
};

#endif //TP1_HOMESCREEN_H