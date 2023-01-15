#ifndef MOVE_H
#define MOVE_H

//Class defines a Move on the tic-tac-toe board
//It indicates the row and col in tic-tac-toe board
//where X or O is to be placed
class Move {

  public:
    
    //Row value of the move in tic-tac-toe board(0,1,2)
    int x;

    //Column value of the move in tic-tac-toe board(0,1,2)
    int y;

    //Constructor for a creating a Move with a given row,col
    Move(int x, int y);

    //Default constructor
    Move();

};
#endif