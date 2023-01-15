#include "board.h"
#ifndef PLAYERS_H
#define PLAYERS_H

//Tic-tac-toe board player
//Abstract base class with pure virtual function play
class Player {

  //Player class by itself maintains no data/state
  //Requird board information is passed as parameter
  //to play method 

  public:
    //Pure virtual function play
    virtual Board *play(Board *) = 0;
};

//Human player is derived from Player
//It needs to implement the virtual method play
class HumanPlayer : public Player {

  Board *play(Board *inboard);

};

//Computer player is derived from Player
//It needs to implement the virtual method play
class ComputerPlayer : public Player {

  Board *play(Board *inboard);

};
#endif