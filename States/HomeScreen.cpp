//
// Created by tom on 9/15/25.
//

#include "headers/HomeScreen.h"

#include <iostream>
#include <ostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "headers/Exploration.h"

using namespace std;


HomeScreen::HomeScreen(StateMachine *stateMachine) : AbstractState(stateMachine) {

    if (!logoTexture.loadFromFile("../ressource/fakemon.png")) {
        std::cout << "Failed to load fakemon.png" << std::endl;
    }
    logoSprite.setTexture(logoTexture);
    if (!font.loadFromFile("../ressource/Pokemon_GB.ttf")) {
        std::cout << "Failed to load font" << std::endl;
    }
    buttonText.setFont(font);
    buttonText.setString("Press S for Start");
    buttonText.setCharacterSize(32);
    buttonText.setFillColor(sf::Color::White);

    button.setFillColor(sf::Color(180, 0, 0));
}

void HomeScreen::handleEvent(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
        gameStarted = true;
    }
}


void HomeScreen::update() {
    if (gameStarted)
        stateMachine->setCurrentState(new Exploration(stateMachine,stateMachine->getWindow()));
}

void HomeScreen::render(sf::RenderWindow &window) {
    window.clear(sf::Color(100,100,100));

    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u logoSize = logoTexture.getSize();

    float scaleX = static_cast<float>(windowSize.x) / logoSize.x;
    logoSprite.setScale(scaleX, scaleX);
    logoSprite.setOrigin(logoSize.x / 2.0f, logoSize.y / 2.0f);
    logoSprite.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);
    window.draw(logoSprite);

    float logoDisplayedHeight = logoSize.y * scaleX;

    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(
        textBounds.left + textBounds.width / 2.0f,
        textBounds.top + textBounds.height / 2.0f
    );
    buttonText.setPosition(
        windowSize.x / 2.0f,
        windowSize.y / 2.0f + logoDisplayedHeight / 2.0f + 10.f);

    button.setSize(sf::Vector2f(
        buttonText.getGlobalBounds().width + 20.f,
        buttonText.getGlobalBounds().height + 10.f));

    button.setOrigin(
        button.getSize().x / 2.0f,
        button.getSize().y / 2.0f);

    button.setPosition(buttonText.getPosition());

    window.draw(button);
    window.draw(buttonText);
}

