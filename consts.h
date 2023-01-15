#ifndef CONSTS_H
#define CONSTS_H

//Constants used for the tic-tac-toe game

//character X as game token
const char X = 'X';

//character O as game token
const char O = 'O';

//Hyphen to indicate empty space on board
const char EMPTY = '-';

//When the score is not yet found to be 1, 0 or -1
//We use -2 to indicate it is yet to be evaluated
const int uninitializedScore = -2;

#endif