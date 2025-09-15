//
// Created by tom on 9/15/25.
//

#ifndef TP1_FOUNDPOKEMON_H
#define TP1_FOUNDPOKEMON_H
#include "StateMachine.h"


class FoundPokemon : public AbstractState {
    public:
    FoundPokemon(StateMachine *stateMachine);
    void state() override;
};


#endif //TP1_FOUNDPOKEMON_H