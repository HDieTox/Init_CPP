//
// Created by tom on 9/15/25.
//

#include "headers/GameOver.h"

#include <iostream>

#include "headers/HomeScreen.h"

using namespace std;

GameOver::GameOver(StateMachine *stateMachine)
    : AbstractState(stateMachine) {

    if (!font.loadFromFile("../ressource/Pokemon_GB.ttf")) {
        std::cout << "Failed to load font" << std::endl;
    }

    gameOverText.setFont(font);
    gameOverText.setString("!! Game Over !!");
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setOrigin(gameOverText.getGlobalBounds().width/2,gameOverText.getGlobalBounds().height/2);
    gameOverText.setPosition(stateMachine->getWindow().getSize().x /2, stateMachine->getWindow().getSize().y/2 );

    restartText.setFont(font);
    restartText.setString("Press ENTER for restart !");
    restartText.setCharacterSize(24);
    restartText.setFillColor(sf::Color::Red);
    restartText.setStyle(sf::Text::Italic);
    restartText.setOrigin(restartText.getGlobalBounds().width/2,restartText.getGlobalBounds().height/2);
    restartText.setPosition(stateMachine->getWindow().getSize().x /2, stateMachine->getWindow().getSize().y - 30);

}

void GameOver::handleEvent(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Enter) {
            stateMachine->setCurrentState(new HomeScreen(stateMachine));
        }
    }
}

void GameOver::update() {

}

void GameOver::render(sf::RenderWindow &window) {
    window.clear(sf::Color::Black);
    window.draw(restartText);
    window.draw(gameOverText);
}
