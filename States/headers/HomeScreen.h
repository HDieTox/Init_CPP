//
// Created by tom on 9/15/25.
//

#ifndef TP1_HOMESCREEN_H
#define TP1_HOMESCREEN_H
#include "StateMachine.h"


class HomeScreen : public AbstractState{
public:
    HomeScreen(StateMachine *stateMachine);
    void state() override;
};

#endif //TP1_HOMESCREEN_H