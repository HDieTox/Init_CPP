//
// Created by tom on 9/15/25.
//

#include "headers/Exploration.h"

#include <iostream>
#include <ostream>
#include <unistd.h>

#include "headers/FoundPokemon.h"
#include "headers/FoundTrainer.h"

using namespace std;

Exploration::Exploration(StateMachine *stateMachine, const sf::RenderWindow &window) : AbstractState(stateMachine) {

    stateDuration = 2.0f + static_cast<float>(rand() % 5);
    stateTimer.restart();

    if (!grassTexture.loadFromFile("../ressource/tallgrass.png"))
        std::cerr << "Failed to load tallgrass.png" << std::endl;
    grassSprite.setTexture(grassTexture);

    sf::Vector2u windowSize = window.getSize();
    unsigned int tileSize = 16;

    for (unsigned int y = 0; y < windowSize.y; y += tileSize) {
        for (unsigned int x = 0; x < windowSize.x; x += tileSize) {
            positions.emplace_back(static_cast<float>(x), static_cast<float>(y));
        }
    }

    while (vibratingIndices.size() < 3) {
        int idx = rand() % positions.size();
        if (std::find(vibratingIndices.begin(), vibratingIndices.end(), idx) == vibratingIndices.end()) {
            vibratingIndices.push_back(idx);
        }
    }

    if (!font.loadFromFile("../ressource/Pokemon_GB.ttf")) {
        std::cout << "Failed to load font" << std::endl;
    }
    text.setFont(font);
    text.setString("Keep Running...");
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
}

void Exploration::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            // ajout d'une Pause dans l'exploration
        }
    }
}

void Exploration::update() {
    if (stateTimer.getElapsedTime().asSeconds() >= stateDuration) {

        Pokedex* pokedex = Pokedex::getInstance();
        int randomIndex = rand() % pokedex->getPokedexSize();
        Pokemon wildPokemon = pokedex->findByIndex(randomIndex);
        int randomFind = rand() % 2;
        if (randomFind) {
            stateMachine->setCurrentState(new FoundPokemon(stateMachine,wildPokemon));
        } else {
            stateMachine->setCurrentState(new FoundTrainer(stateMachine));
        }
    }
}

void Exploration::updateVibrations() {
    if (vibrationClock.getElapsedTime().asSeconds() >= vibrationInterval) {
        vibratingIndices.clear();

        while (vibratingIndices.size() < nbVibrating) {
            int idx = rand() % positions.size();
            if (ranges::find(vibratingIndices, idx) == vibratingIndices.end()) {
                vibratingIndices.push_back(idx);
            }
        }
        vibrationClock.restart();
    }
}

void Exploration::render(sf::RenderWindow &window) {

    sf::Vector2u windowSize = window.getSize();
    window.clear(sf::Color::Green);

    updateVibrations();

    for (size_t i = 0; i < positions.size(); ++i) {
        sf::Vector2f pos = positions[i];

        if (ranges::find(vibratingIndices, i) != vibratingIndices.end()) {
            const float offsetX = (rand() % 3) - 1;
            const float offsetY = (rand() % 3) - 1;
            pos.x += offsetX;
            pos.y += offsetY;
        }
        grassSprite.setPosition(pos);

        window.draw(grassSprite);
    }

    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(
        textBounds.left + textBounds.width / 2.0f,
        textBounds.top + textBounds.height / 2.0f
    );
    text.setPosition(
        windowSize.x / 2.0f,
        windowSize.y / 2.0f
        );
    window.draw(text);

    Exploration::update();
}
