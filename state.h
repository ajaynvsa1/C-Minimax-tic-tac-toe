#include "board.h"
#ifndef STATE_H
#define STATE_H

//Class for defining game state used by minimax
class State {

  private:
    //Pointer to the tic tac toe game board
    Board *board;

    //Is this the end of game 
    bool isTerminal;

    //Is this the turn of X or O
    char playerXO;

    //List of Moves possible given the board in this state
    vector<Move> stateOptions;

    //Scores(1, 0, -1) corresponding to each move in the 
    //stateOptions list
    vector<int> optionScores;

    //Next action or Move to process to create next 
    //child game state
    int unprocessedAction;

    //Pointer to parent game state
    State *parent;

    //The Move that when applied on parent game states board
    //gives this current game state
    Move initAction;

    //Holds the score corresponding to this game state when 
    //this gamestates evaluation is done
    int score;

    //The move from one of the child gamestates that 
    // won and was used to decide this gamestates score
    Move scoreProvider;

  public:

    //Constructor that takes a pointer to a Board, 
    //initAction - Move on parent board that results in the one being created
    //and pointer to parent game state
    State(Board *board, Move initAction, State *parent);

    //Destructor of this game state
    ~State();

  //Minimax algorithm that uses the game state to generate computers move
  //is made a friend function of state
  friend Move minimax(Board *board);

  //No need to have getters and setters as the gamestate is operated by
  //only minimax which is a friend.
};
#endif