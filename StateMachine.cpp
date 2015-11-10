#include <Arduino.h>
#include "StateMachine.h"

// Creates a new instance and sets the start time of the
// initial state.
StateMachine::StateMachine() {
  currentState = NULL;
  newState = NULL;
}

void StateMachine::beginState(State state) {
  currentState = state;
  stateStartTime = millis();
}

// Executes the current state. If that state causes a new state
// to be entered, also execute that new state, and so on, until
// no new state is entered.
void StateMachine::doState() {
  do {
    newState = NULL;
    currentState();
    if (newState != NULL) {
      currentState = newState;
    }
  } while (newState != NULL);
}

// Gets the lenth of time, in milliseconds, since the current
// state was entered.
unsigned long StateMachine::getStateTime() {
  return millis() - stateStartTime;
}

// Gets the current state.
State StateMachine::getCurrentState() {
  return currentState;
}
