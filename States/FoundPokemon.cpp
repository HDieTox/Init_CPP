#include "headers/FoundPokemon.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "headers/Exploration.h"

FoundPokemon::FoundPokemon(StateMachine *stateMachine, const Pokemon& pokemon)
    : AbstractState(stateMachine), wildPokemon(pokemon) {

    if (!font.loadFromFile("../ressource/Pokemon_GB.ttf")) {
        std::cout << "Failed to load font" << std::endl;
    }

    encounterText1.setFont(font);
    encounterText1.setString("You encountered a wild");
    encounterText1.setCharacterSize(32);
    encounterText1.setFillColor(sf::Color::Black);

    encounterText2.setFont(font);
    encounterText2.setString(wildPokemon.getName() + "!");
    encounterText2.setCharacterSize(32);
    encounterText2.setFillColor(sf::Color::Black);
    encounterText2.setStyle(sf::Text::Italic);

    captureText.setFont(font);
    captureText.setString("Capture (C)");
    captureText.setCharacterSize(24);
    captureText.setFillColor(sf::Color::White);

    fleeText.setFont(font);
    fleeText.setString("Flee (F)");
    fleeText.setCharacterSize(24);
    fleeText.setFillColor(sf::Color::White);

    captureButton.setFillColor(sf::Color::Blue);
    fleeButton.setFillColor(sf::Color::Red);
}

void FoundPokemon::update() {

}

void FoundPokemon::render(sf::RenderWindow &window) {
    window.clear(sf::Color::White);

    sf::Vector2u windowSize = window.getSize();

    sf::FloatRect encounterBounds1 = encounterText1.getLocalBounds();
    encounterText1.setOrigin(
        encounterBounds1.left + encounterBounds1.width / 2.0f,
        encounterBounds1.top + encounterBounds1.height / 2.0f
    );
    encounterText1.setPosition(
        windowSize.x / 2.0f,
        windowSize.y / 4.0f
    );
    sf::FloatRect encounterBounds2 = encounterText2.getLocalBounds();
    encounterText2.setOrigin(
        encounterBounds2.left + encounterBounds2.width / 2.0f,
        encounterBounds2.top + encounterBounds2.height / 2.0f
    );
    encounterText2.setPosition(
        windowSize.x / 2.0f,
        windowSize.y / 4.0f + encounterBounds2.getSize().y + 5
    );

    const float buttonSpacing = 50.f;

    sf::FloatRect captureTextBounds = captureText.getLocalBounds();
    captureText.setOrigin(
        captureTextBounds.left + captureTextBounds.width / 2.0f,
        captureTextBounds.top + captureTextBounds.height / 2.0f
    );

    captureButton.setSize(sf::Vector2f(
        captureText.getGlobalBounds().width + 40.f,
        captureText.getGlobalBounds().height + 20.f
    ));

    captureButton.setOrigin(
        captureButton.getSize().x / 2.0f,
        captureButton.getSize().y / 2.0f
    );

    captureButton.setPosition(
        windowSize.x / 2.0f - captureButton.getSize().x / 2.0f - buttonSpacing / 2.0f,
        windowSize.y / 2.0f
    );

    captureText.setPosition(captureButton.getPosition());

    sf::FloatRect fleeTextBounds = fleeText.getLocalBounds();
    fleeText.setOrigin(
        fleeTextBounds.left + fleeTextBounds.width / 2.0f,
        fleeTextBounds.top + fleeTextBounds.height / 2.0f
    );

    fleeButton.setSize(sf::Vector2f(
        fleeText.getGlobalBounds().width + 40.f,
        fleeText.getGlobalBounds().height + 20.f
    ));

    fleeButton.setOrigin(
        fleeButton.getSize().x / 2.0f,
        fleeButton.getSize().y / 2.0f
    );

    fleeButton.setPosition(
        windowSize.x / 2.0f + fleeButton.getSize().x / 2.0f + buttonSpacing / 2.0f,
        windowSize.y / 2.0f
    );

    fleeText.setPosition(fleeButton.getPosition());

    window.draw(encounterText1);
    window.draw(encounterText2);
    window.draw(captureButton);
    window.draw(fleeButton);
    window.draw(captureText);
    window.draw(fleeText);
}

void FoundPokemon::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::C) {
            stateMachine->getPlayerTeam().captureWildPokemon(wildPokemon);

            stateMachine->setCurrentState(new Exploration(stateMachine, stateMachine->getWindow()));
        } else if (event.key.code == sf::Keyboard::F) {
            stateMachine->setCurrentState(new Exploration(stateMachine, stateMachine->getWindow()));
        }
    }
}