#include "sGameState.h"

sGameState::sGameState()
{
    //ctor
}

sGameState::~sGameState()
{
    //dtor
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameState::setNextState(int n_state)
{
    nextState=n_state;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
int sGameState::getNextState()
{
    return nextState;
}

