//
// Created by tom on 9/15/25.
//

#ifndef TP1_EXPLORATION_H
#define TP1_EXPLORATION_H
#include "StateMachine.h"


class Exploration : public AbstractState {
private:
    sf::Clock stateTimer;
    float stateDuration;

    sf::Texture grassTexture;
    sf::Sprite grassSprite;
    std::vector<sf::Vector2f> positions;
    std::vector<int> vibratingIndices;
    sf::Clock vibrationClock;
    const int nbVibrating = 150;
    const float vibrationInterval = 0.5f;

    sf::Font font;
    sf::Text text;
public:
    Exploration(StateMachine *stateMachine, const sf::RenderWindow &window);


    void updateVibrations();

    void handleEvent(const sf::Event &event);

    void render(sf::RenderWindow &window) override;
    void update() override;

    ~Exploration() override = default;
};



#endif //TP1_EXPLORATION_H