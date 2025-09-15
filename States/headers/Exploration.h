//
// Created by tom on 9/15/25.
//

#ifndef TP1_EXPLORATION_H
#define TP1_EXPLORATION_H
#include "StateMachine.h"


class Exploration : public AbstractState {
public:
    Exploration(StateMachine *stateMachine);
    void state() override;

};


#endif //TP1_EXPLORATION_H