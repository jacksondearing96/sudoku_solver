#include "Position.h"

#include <iostream>

Position::Position()
{
}

// initialises position based on arguments
// also checks that the position is valid
// terminates program if invalid position is set
Position::Position(int x, int y)
  : row_(x),
    col_(y)
{
    if (IsValid() == false)
    {
      std::cout << "Invalid position set" << std::endl;
      exit(0);
    }
}

// returns true if position is in valid range [0,2]
// returns false otherwise
bool Position::IsValid() const
{
    // check valid row
    if (row_ > 2 || row_ < 0)
    {
        return false;
    }

    // check valid col
    if (col_ > 2 || col_ < 0)
    {
        return false;
    }

  return true;
}

// returns true if rows and cols are equal
// returns false otherwise
bool Position::operator==(const Position& rhs) const
{
  return (this -> row_ == rhs.row_ &&
          this -> col_ == rhs.col_);
}
