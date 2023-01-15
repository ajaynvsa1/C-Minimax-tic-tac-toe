#include "board.h"
#include "consts.h"
#include "move.h"
#include <iostream>
#include <vector>
using namespace std;

//Default constructor
Board::Board() {
  
  //Initialize for a 3X3 tic-tac=toe board
  rows = 3;
  cols = 3;

  //Initial count so that turn is that of X
  turnCount = 0;

  //Allocate an array of 3 char pointer
  board = new char *[3];

  //Go over rows
  for (int i = 0; i < 3; i++) {

    //Allocate a char array of size 3  
    board[i] = new char[3];
    
    for (int j = 0; j < 3; j++) {

      //Initialize the board as EMPTY
      board[i][j] = EMPTY;
    }
  }
}


//Constructor that takes rows and cols
//(Overall code works only for 3X3 board now)
//This is for future enhancement
Board::Board(int rows, int cols) {

  //Initialize for a rowsXcols tic-tac=toe board
  this->rows = rows;
  this->cols = cols;

  //Initial count so that turn is that of X
  turnCount = 0;

  //Allocate an array of rows no of char pointer
  board = new char *[rows];

  //Go over rows
  for (int i = 0; i < rows; i++) {

    //Allocate a char array of size cols  
    board[i] = new char[cols];
    
    for (int j = 0; j < cols; j++) {

      //Initialize the board as EMPTY
      board[i][j] = EMPTY;
    }
  }
}

//Copy constructor
Board::Board(Board &board) {

  //Initialize for same dimensions as input tic-tac=toe board
  this->rows = board.rows;
  this->cols = board.cols;

  //Copy turn count
  this->turnCount = board.turnCount;

   //Allocate an array of rows no of char pointer
  this->board = new char *[rows];

  //Go over rows
  for (int i = 0; i < rows; i++) {

    //Allocate a char array of size cols  
    this->board[i] = new char[cols];

    for (int j = 0; j < cols; j++) {
      
      //Initialize the board with contents of input board
      this->board[i][j] = board[i][j];
    }
  }
}

//Copying from input board *
Board::Board(Board *board) {

   //Initialize for same dimensions as input tic-tac=toe board
  this->rows = board->rows;
  this->cols = board->cols;

  //Copy turn count
  this->turnCount = board->turnCount;

   //Allocate an array of rows no of char pointer
  this->board = new char *[rows];

  //Go over rows
  for (int i = 0; i < rows; i++) {

    //Allocate a char array of size cols  
    this->board[i] = new char[cols];
    
    for (int j = 0; j < cols; j++) {

      //Initialize the board with contents of input board
      this->board[i][j] = (*board)[i][j];
    }
  }
}

//Find if it is X or O to be played on board
char Board::turn() {
  // Since 0-based,
  // if even, X
  // odd, O.
  return (turnCount % 2) == 0 ? 'X' : 'O';
}

//Get list of Moves possible on this board
vector<Move> Board::options() {
  
  Board &board = *this;
  vector<Move> result;

  //Go over 3 rows
  for (int i = 0; i < 3; i++) {

    //Go over 3 cols
    for (int j = 0; j < 3; j++) {

      //If the spot is empty 
      if (board[i][j] == EMPTY) {
        
        Move p;
        p.x = i;
        p.y = j;
        //Add to list of possible moves
        result.push_back(p);
      }
    }
  }

  //Return the list of possible Moves
  return result;
}

//Find if there is a winner given the 3X3 board
char Board::winner() {

  //Check all 3 rows for any 3 consecutive X or O
  for (int i = 0; i < 3; i++)
    if (board[i][0] != EMPTY)
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        return board[i][0];

  //Check all 3 columns for any 3 consecutive X or O
  for (int i = 0; i < 3; i++)
    if (board[0][i] != EMPTY)
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        return board[0][i];

  //Check diagonal one for 3 consecutive X or O
  if (board[0][0] != EMPTY)
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
      return board[0][0];
  
  //Check diagonal two for 3 consecutive X or O
  if (board[2][0] != EMPTY)
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
      return board[2][0];
  
  //There is no winner
  return EMPTY;
}

//Is the game over
bool Board::isEnd() {

  //Game is over if there is a winner or if there is no empty spot on the board
  return ((this->options().size() == 0) || (this->winner() != EMPTY));
}

//For a board with game over, value is 1 winner is X
// value is -1 if winner is -1, value is 0 if it is a draw
int Board::eval() {
  char winner = this->winner();

  if (winner == O)
    return -1;
  else if (winner == X)
    return 1;

  return 0;
}

//Destructor for board to free memory
Board::~Board() {
  
  for (int i = 0; i < rows; i++) {
    //Delete each row
    delete board[i];
  }
  //Delete overall board
  delete[] board;
}

//Overload array index operator to take Move Object as index
//Returns a reference so that it can be used in left hand side of assignment
char &Board::operator[](Move p) const { 
  
  return board[p.x][p.y]; 
  
}

//Overload array index operator to use Board object as 2D array
//Returns a reference so that it can be used in left hand side of assignment
char *Board::operator[](int i) const { 

  //Return row char pointer
  return board[i]; 
}

//Overload ostream operator to display the board
ostream &operator<<(ostream &out, const Board &board){

  //Go over all rows
  for (int i = 0; i < 3; i++) {

    //Go over all columns
    for (int j = 0; j < 3; j++) {
    
      out << board[i][j] << " ";
    
    }
    
    out << endl;
  }
  
  return out;
}