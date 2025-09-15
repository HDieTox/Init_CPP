//
// Created by tom on 9/15/25.
//

#ifndef TP1_FOUNDTRAINER_H
#define TP1_FOUNDTRAINER_H
#include "StateMachine.h"


class FoundTrainer : public AbstractState {
public:
    FoundTrainer(StateMachine* stateMachine);
    void state() override;
};


#endif //TP1_FOUNDTRAINER_H