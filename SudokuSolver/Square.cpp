#include "Square.h"
#include "Position.h"

#include <vector>
#include <iostream>

using namespace std;

Square::Square()
{
  data = new int*[3];
  for (int i=0 ; i<3 ; i++)
  {
    data[i] = new int[3];
  }
}

void Square::setPosition(Position pos) {
  position = pos;
}

vector<Position> Square::getEmptyPositions() {
  Position emptyPos;
  vector<Position> emptyPositions;

  for (int i=0 ; i<3 ; i++) {
    for (int j=0 ; j<3 ; j++) {
      if (data[i][j] == 0) {
        emptyPos.row_ = i;
        emptyPos.col_ = j;
        emptyPositions.push_back(emptyPos);
      }
    }
  }

  return emptyPositions;
}


vector<int> Square::getMissingNums() {
  vector<int> nums;
  for (int i=1 ; i<10 ; i++)
    nums.push_back(i);

  for (int i=0 ; i<3 ; i++) {
    for (int j=0 ; j<3 ; j++) {
      for (int k=nums.size()-1 ; k>=0 ; k--) {
        if (data[i][j] == nums.at(k))
          nums.erase(nums.begin() + k);
      }
    }
  }
  return nums;
}


vector<Position> Square::locateNumber(int num) {
  vector<Position> positions;

  for (int i=0 ; i<3 ; i++) {
    for (int j=0 ; j<3 ; j++) {
      if (data[i][j] == num){
        Position p(i, j);
        positions.push_back(p);
        return positions;
      }
    }
  }
  return positions;
}

void Square::setHorizontallyRelatedSquares(vector<Square> inputSquares) {
  horizontallyRelatedSquares = inputSquares;
}

void Square::setVerticallyRelatedSquares(vector<Square> inputSquares) {
  verticallyRelatedSquares = inputSquares;
}


vector<Position> Square::getPossiblePositionsForNum(int num) {

  vector<Position> possiblePositions;
  for (int i=0 ; i<3 ; i++) {
    for (int j=0 ; j<3 ; j++) {
      if (data[i][j] == 0) {
        possiblePositions.push_back(Position(i,j));
      }
    }
  }

  for (int i=0 ; i<2 ; i++) {
    vector<Position> excludePos = horizontallyRelatedSquares.at(i).locateNumber(num);
    if (excludePos.size() != 0) {
      for (int i=possiblePositions.size()-1 ; i>=0 ; i--) {
        if (possiblePositions.at(i).row == excludePos.at(0).row_) {
          possiblePositions.erase(possiblePositions.begin() + i);
        }
      }
    }
  }

  for (int i=0 ; i<2 ; i++) {
    vector<Position> excludePos = verticallyRelatedSquares.at(i).locateNumber(num);

    if (excludePos.size() != 0) {
      for (int i=possiblePositions.size()-1 ; i>=0 ; i--) {
        if (possiblePositions.at(i).col == excludePos.at(0).col_) {
          possiblePositions.erase(possiblePositions.begin() + i);
        }
      }
    }
  }

  return possiblePositions;
}
