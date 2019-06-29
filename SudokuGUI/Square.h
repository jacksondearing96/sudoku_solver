#ifndef SQUARE_H
#define SQUARE_H

#include "Position.h"

#include <vector>

using namespace std;

class Square {

public:

  Square();

  Position position;
  void setPosition(Position);

  int** data;

  vector<Position> getEmptyPositions();
  vector<int> getMissingNums();

  vector<Position> locateNumber(int);

  vector<Square> horizontallyRelatedSquares;
  vector<Square> verticallyRelatedSquares;
  void setHorizontallyRelatedSquares(vector<Square>);
  void setVerticallyRelatedSquares(vector<Square>);

  vector<Position> getPossiblePositionsForNum(int num);

};

#endif
