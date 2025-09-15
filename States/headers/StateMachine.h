//
// Created by tom on 9/15/25.
//

#ifndef TP1_STATEMACHINE_H
#define TP1_STATEMACHINE_H


class StateMachine;

class AbstractState {
protected:
    StateMachine *stateMachine;
    AbstractState(StateMachine *stateMachine);
public:
    virtual ~AbstractState() = default;
    virtual void state() = 0;
};

class StateMachine {
private:
    AbstractState *currentState;
public:
    StateMachine();
    void setCurrentState(AbstractState *currentState);
    void state() const;
};

#endif //TP1_STATEMACHINE_H