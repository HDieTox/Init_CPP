#include <iostream>

#include "States/headers/StateMachine.h"
#include "Pokemon/headers/PCPokemon.h"
#include "Pokemon/headers/Pokedex.h"
#include "Pokemon/headers/Pokemon.h"
#include "Pokemon/headers/TeamPokemon.h"
#include <SFML/Graphics.hpp>

#include "States/headers/HomeScreen.h"
int main() {
    sf::RenderWindow window(sf::VideoMode(960, 540), "Mon Jeu Pokemon");
    StateMachine* game = new StateMachine(window,1,"Tom's PC");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }

            // Passez tous les événements à la machine à état
            game->handleEvent(event);
        }

        game->update();
        game->render();
        window.display();
    }

    delete game;
    return 0;
}
