#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Position.h"

#include <stack>
#include <vector>

class GameState {
public:

  GameState(int** state_,
            Position squarePosition_,
            int guessNum_,
            Position guessedPosition_,
            std::vector<Position> alternativePositions_);

  int** state;

  Position squarePosition;

  int guessNum;
  Position guessedPosition;
  std::vector<Position> alternativePositions;

};

#endif // GAMESTATE_H
