#ifndef POSITION_H
#define POSITION_H

// Represents a two dimensional position
// on within an arbitrary 3x3 square
class Position {

public:
  Position();
  Position(int x, int y);

  int row_;
  int col_;

  // rows and cols are limited to values between 0 and 2 inclusive
  // method returns true rows and cols are in valid range
  // returns false otherwise
  bool IsValid() const;

  // returns true if the rows and columns of two
  // positions are equal
  bool operator==(const Position& rhs) const;
};

#endif
