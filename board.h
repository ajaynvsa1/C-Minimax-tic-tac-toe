#include <iostream>
#include <vector>
#include "move.h"

using namespace std;

#ifndef BOARD_H
#define BOARD_H

//Tic-tac-toe board
class Board {
  private:
    //No of rows - currently works for 3X3 board only
    int rows;

    //No of columns - currently works for 3X3 board only
    int cols;

    //To keep track if it is turn of X or O
    int turnCount; 

    //Pointer to 2D array of Chars
    char **board;
  public:

    //Default constructor - creates 3X3 board
    Board();

    //Constructor that takes max rows and columns for
    //creating a board of that dimension
    Board(int rows, int cols);

    //Copy constructor as there is a char ** member
    Board(Board &board);

    //Constructor that takes pointer to another board
    Board(Board *board);

    //Return X or O to indicate whose turn it is
    char turn();

    //Returns vector of Moves that are possible on this board
    vector<Move> options();

    //Returns X or O if there is a winner or EMPTY if none
    char winner();

    //Returns true if there is a winner or if it is a draw
    bool isEnd();

    //Evaluates a terminal board value as 0, 1 or -1
    int eval();

    //Destructor to deallocate 2D array memory
    ~Board();

    //Overloading subscript operator to use Move object as index
    char &operator[](Move p) const;

    //Overloading subscript operator to return char * 
    //So that 2D subscript can be used with Board object 
    char *operator[](int i) const;

  //Overloaded stream insertion operatof for display of board is a friend
  friend ostream &operator<<(ostream &out, const Board &board);

  //Utility function that applies a moved on input board and creates 
  // a new output board and returns is also declared as a friend
  friend Board *changedBoard(Board *board, Move p);
};

//Overloading stream insertion operator to display Board
ostream &operator<<(ostream &out, const Board &board);
#endif