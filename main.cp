#include <iostream>
#include <vector>

using namespace std;

#include "move.h"
#include "board.h"
#include "consts.h"
#include "gameUtility.h"
#include "players.h"


//Program for playing tic-tac-toe game with the computer
int main() {

  //Allocate memory and initialize a default tic-tac-toe board
  Board *board = new Board();

  //Response to see if the human player plays first
  char resp;

  //To keep track if it is playerA or B who needs to play
  bool playerAturn = true;

  //Two base class pointers playerA and playerB
  //- one to point to human player and another to point to 
  //computer player
  Player *playerA = nullptr;
  Player *playerB = nullptr;

  //Get user input to see if they like to go first
  cout << "Would you like to go first: y/n? ";
  cin >> resp;

  //If human player plays first, playerA is initialized
  //with HumanPlayer object and playerB is initialized with ComputerPlayer
  //Else it is vice versa
  
  if (resp == 'y') {
    
    playerA = new HumanPlayer;
    playerB = new ComputerPlayer;
    
  } 
  else {
    
    playerA = new ComputerPlayer;
    playerB = new HumanPlayer;
    
  }

  //As long as the game is not over
  while (true) {

    //Print the tic-tac-toe board
    cout << endl;
    cout << *board;
    cout << endl;

    //Is the game over?
    if (board->isEnd()) {

      //Print game ended and print the winner if one exists
      cout << "Game over." << endl;

      //Get boards winner
      char winner = board->winner();
      if (winner != EMPTY) {
        
        //Print if there is a valid winner
        cout << winner << " wins." << endl;
      }  
      else
        cout << "Its a DRAW" << endl;

      break;
    }

    /*Call play virtual method for the playerA or B
    based on whose turn it is.
    If it is HumanPlayer object being pointed to by Player *
    Move would be obtained from user
    If it is ComputerPlayer object being pointed to by Player *
    Minimax will be called to find the move to be played by the computer*/
    if (playerAturn) {
      
      board = playerA->play(board);
      playerAturn = false;
      
    } 
    else {
      
      board = playerB->play(board);
      playerAturn = true;
      
    }
    
  }
}
