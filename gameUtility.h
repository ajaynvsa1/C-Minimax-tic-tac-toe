#include "state.h"
#include "consts.h"
#ifndef GAMEUTILITY_H
#define GAMEUTILITY_H

//Utility function for updating a board with a move
//This creates a new board different from the input one and returns
Board *changedBoard(Board *board, Move p);

//Returns max of all numbers in the vector and corresponding index is outparam
int max(vector<int> nums, int &index);

//Returns min of all numbers in the vector and corresponding index is outparam
int min(vector<int> nums, int &index);

//Minimax algorithm that takes input board and returns optimal Move to play
Move minimax(Board *board);

#endif