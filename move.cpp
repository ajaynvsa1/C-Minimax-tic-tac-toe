#include "move.h"

//Constructor for Move that takes the row and col
Move::Move(int x, int y) {
  
  this->x = x;
  this->y = y;
  
}

//Default constructor
Move:: Move() {
  
  this->x = -1;
  this->y = -1;
  
}