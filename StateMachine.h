#ifndef StateMachine_h
#define StateMachine_h

/**
 * Defines a State to be a pointer to a function returning
 * another state to execute. The function may return NULL
 * to stay in the current state.
 */
typedef void (*State)();

/**
 * Implement a finite state machine. States are void functions
 * taking no arguments. A state can cause a transition to a new
 * state by calling beginState(). States are normally invoked
 * by periodically calling doState(), which executes the current
 * state. If that state transitions to a new state, it is immediately
 * invoked, and so on, until there are no more immediate transitions.
 */
class StateMachine {
  
  public:
  
    /**
     * Creates a new state machine instance.
     */
    StateMachine();
  
    /**
     * Enters a new state. Each state is a zero-arg function
     * returning a new state to enter and execute, or NULL to
     * stay in the current state.
     *
     * @param stateFn a function to execute the state
     */
    void beginState(State stateFn);
    
    /**
     * Executes the current state. If that function begins a new
     * state, that new state will also execute, until no new
     * state is entered.
     */
    void doState();
    
    /**
     * Gets the time that the state machine has been in the
     * current state.
     */
    unsigned long getStateTime();
    
    /**
     * Gets the current state we are executing.
     *
     * @return the current state function
     */
    State getCurrentState();

  private:
  
    /** The current state function. */
    State currentState;
    
    /** The new state to start, or NULL if no new state. */
    State newState;
    
    /** The time at which the state was entered, in milliseconds. */
    unsigned long stateStartTime;
    
};

#endif StateMachine_h
