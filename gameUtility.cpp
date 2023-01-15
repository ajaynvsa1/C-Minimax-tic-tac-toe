#include "gameUtility.h"

//Utility function that takes pointer to input board
//And the Move to be applied on it
//It creates a new output board and returns
Board *changedBoard(Board *board, Move p) {
  //Create a new copy board using input board
  Board *newBoard = new Board(board);

  //If the game has ended return the board
  //without applying the input Move p
  if (board->isEnd()) {
    return newBoard;
  }

  //Check if input Move p is valid for 3X3 tic-tac-toe board
  if (p.x > 2 || p.y > 2 || p.x < 0 || p.y < 0) {
    return newBoard;
  }

  //Check if the turn is that of X or O
  char temp = board->turn();

  //Update board to keep track of turn
  newBoard->turnCount++;

  //Update new board with input Move p
  (*newBoard)[p] = temp;

  //return the updated new board
  return newBoard;
}

//Utility function to find the max of all numbers in nums
//Returns max value
//Updates reference index with that of max value
int max(vector<int> nums, int &index) {

  //Initialize with least value
  int maxNum = -2147483647;

  //Go over vector looking for max value
  for (int i = 0; i < nums.size(); i++) {

    //Update maxNum if something greater than that is found
    if (nums[i] > maxNum) {
      
      maxNum = nums[i];
      
      //Keep track of index corresponding to maxNum
      index = i;
      
    }
  }

  //return final max value
  return maxNum;
}

//Utility function to find the min of all numbers in nums
//Returns min value
//Updates reference index with that of max value
int min(vector<int> nums, int &index) {

  //Initialize with max value
  int minNum = 2147483647;

  //Go over the vector looking for the min value
  for (int i = 0; i < nums.size(); i++) {

    //Update minNumb if something lower is found
    if (nums[i] < minNum) {
      
      minNum = nums[i];
      //Keep track of index corresponding to minNum
      index = i;
      
    }
  }

  //Return final min value
  return minNum;
}

//Utility function to implement minimax algorithm 
//This returns the optimal move to play for the given board
Move minimax(Board *board) {

  //Dummy move used in init of scoreprovider to begin with
  const Move uninitMove(-1,-1); 

  //Null state to use for parent to begin with
  State *uninitState = NULL;

  //Create new copy board from input board
  Board *newBoard = new Board(board);

  //Create game state corresponding to input board
  State *newState =
      new State(newBoard, uninitMove, uninitState);

  //Create a stack to hold game state pointers
  vector<State *> stack;

  //Push the initial input state into stack
  stack.push_back(newState);

  //Do depth first search of game tree - evaluating states from the stack
  while (!stack.empty()) {
    
    //Get top of stack state
    State *curr = stack[stack.size() - 1]; // curr is e.o.s

    // curr game state is due to be scored if curr is terminal 
    //or all children game states of curr have been evaluated
    if (curr->isTerminal ||
        curr->unprocessedAction == curr->stateOptions.size()) { 
      
      // Not terminal but due to be scored as children have been evaluated
      if (!curr->isTerminal) {
        
        // Ternary operator for scoring
        int index = 0; 

        //Find the score from all moves possible from this board
        curr->score = curr->board->turn() == X ? max(curr->optionScores,index)
                                             : min(curr->optionScores,index);
        //Update with the move that provided the best score
        curr->scoreProvider = curr->stateOptions[index];
      }
      
      //If state is not the input state at root - for every other state beneath
      if (curr->parent != NULL) {
      
        //Get the next unprocessed move index that is possible on parent board
        int index = curr->parent->unprocessedAction - 1;

        //Pass on score to parent for the Move that generated this game state
        curr->parent->optionScores[index] = curr->score;
        
        
        // If child has extreme score in alignment with parent player's
        // objective, Then no need to check other children to score parent
        if (curr->score == 1 && curr->parent->playerXO == X)
          curr->parent->unprocessedAction = curr->parent->stateOptions.size();
        else if (curr->score == -1 && curr->parent->playerXO == O)
          curr->parent->unprocessedAction = curr->parent->stateOptions.size();
      }
      
      //Pop the one that is evaluated and has updated its parent
      stack.pop_back();
      delete curr;
    }
    // Add new State to stack
    else {
      
      //Push children states into the stack
      Move initAction;

      //Last processed action/Move in curr that is being used for creating child state
      initAction = curr->stateOptions[curr->unprocessedAction];

      //curr is the parent of the new state being created
      stack.push_back(
          (new State(changedBoard(curr->board, initAction), initAction, curr)));
      
      //Move the unprocessed action/Move index forward
      curr->unprocessedAction++;
    }
  }

  //Return the Move that yielded the best score for input state
  return (newState->scoreProvider);
}
