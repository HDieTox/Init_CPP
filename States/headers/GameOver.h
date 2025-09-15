//
// Created by tom on 9/15/25.
//

#ifndef TP1_GAMEOVER_H
#define TP1_GAMEOVER_H
#include "StateMachine.h"


class GameOver : public AbstractState{
public:
    GameOver(StateMachine* stateMachine);
    void state() override;
};


#endif //TP1_GAMEOVER_H