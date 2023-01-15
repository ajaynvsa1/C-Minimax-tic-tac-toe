#include "state.h"
#include "consts.h"

//Constructor for State that takes Board *, Move that created this state
//and pointer to parent game state
State::State(Board *board, Move initAction, State *parent) {
  
  const Move uninitMove(-1,-1); 
  //Initialize board pointer member
  this->board = board;

  //Has the game ended on this board
  this->isTerminal = board->isEnd();

  //On this board is it player X or O that needs to play
  this->playerXO = board->turn();

  //List of Moves possible on this board
  this->stateOptions = board->options();

  //List that containes scores corresponding to Moves
  for (int i = 0; i < stateOptions.size(); i++) {
    optionScores.push_back(0);
  }                              

  //Next Move to be used for creating child state
  this->unprocessedAction = 0;   

  //Move from parent that created this state
  this->initAction = initAction; 

  //Pointer to parent state
  this->parent = parent;   

  //Evaluate board if it is terminal 
  this->score = isTerminal ? board->eval() : uninitializedScore;

  //Move associated with Child State that eventually has winning score
  this->scoreProvider = uninitMove;
}

//Destructor for State
State::~State() {

  //Deallocate board memory
  delete board;
  
}