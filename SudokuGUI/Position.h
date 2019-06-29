#ifndef POSITION_H
#define POSITION_H

// represents the two dimensional position
// positions are relative to top left element
// which has position {0,0}
class Position {

public:
  Position();
  Position(int x, int y);

  int row;
  int col;

  // rows and cols are limited to values between 0 and 2 inclusive
  // method returns true rows and cols are in valid range
  // returns false otherwise
  bool checkValidPosition();

  // returns true if the rows and columns of two
  // positions are equal
  bool operator==(const Position& RHS);
};

#endif
