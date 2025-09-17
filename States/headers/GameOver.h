//
// Created by tom on 9/15/25.
//

#ifndef TP1_GAMEOVER_H
#define TP1_GAMEOVER_H
#include "StateMachine.h"


class GameOver : public AbstractState{
private:
    sf::Font font;
    sf::Text restartText;
    sf::Text gameOverText;
public:
    GameOver(StateMachine* stateMachine);
    void handleEvent(const sf::Event& event) override;
    void update() override;
    void render(sf::RenderWindow &window) override;

    ~GameOver() override = default;
};


#endif //TP1_GAMEOVER_H