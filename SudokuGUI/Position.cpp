#include "Position.h"

#include <iostream>

using namespace std;

Position::Position() {
}

// initialises position based on arguments
// also checks that the position is valid
// terminates program if invalid position is set
Position::Position(int x, int y)
  : row(x), col(y) {
    if (!checkValidPosition()) {
      cout << "Invalid position set" << endl;
      exit(0);
    }
}

// returns true if position is in valid range [0,2]
// returns false otherwise
bool Position::checkValidPosition()
{
  // check valid row
  if (row > 2 || row < 0)
    return false;

  // check valid col
  if (col > 2 || col < 0)
    return false;

  return true;
}

// returns true if rows and cols are equal
// returns false otherwise
bool Position::operator==(const Position& RHS) {
  return (this -> row == RHS.row &&
          this -> col == RHS.col);
}
