#include <iostream>
using namespace std;
#include "consts.h"
#include "players.h"
#include "gameUtility.h"

//Virtual function play implementation for HumanPlayer
//This gets Move to be played from user
Board *HumanPlayer::play(Board *inboard) {

  Board *board = inboard;
  Move p;
  
  //Get a valid Move from user through CLI
  while (true) {
  
    //Prompt for user input
    cout << "Enter Move in tic-tac-toe board (row space col 0-based): ";

    //Get the Move user wants to play
    cin >> p.x >> p.y;

    //Check if it is within board limits
    if (p.x > 2 || p.y > 2 || p.x < 0 || p.y < 0) {
      cout << "Invalid Move" << endl;
      continue;
    }

    //Check if the Move is not for a space that is taken
    if ((*board)[p] != EMPTY) {
      cout << "It is taken pick something else" << endl;
      continue;
    }
    break;
  }

  //Apply the Move on the board to to get a new updated board
  board = changedBoard(board, p);

  //return the updated board
  return board;
}

//Virtual function play implementation for ComputerPlayer
//This gets Move to be played from user
Board *ComputerPlayer::play(Board *inboard) {

  Board *board = inboard;
  Move p;
  
  cout << "COMPUTER THINKING..."  << endl;
  
  //Call Minimax to find the optimal Move
  p = minimax(board);

  //Apply the Move on the board to to get a new updated board
  board = changedBoard(board, p);

  //return the updated board
  return board;
}