#include "GameState.h"

using namespace std;

GameState::GameState(int** state_,
                     Position squarePosition_,
                     int guessNum_,
                     Position guessedPosition_,
                     vector<Position> alternativePositions_)

: squarePosition(squarePosition_),
  guessNum(guessNum_),
  guessedPosition(guessedPosition_),
  alternativePositions(alternativePositions_)

{
  state = new int*[9];
  for (int i=0 ; i<9 ; i++) {
    state[i] = new int[9];
  }

  for (int i=0 ; i<9 ; i++) {
    for (int j=0 ; j<9 ; j++) {
      state[i][j] = state_[i][j];
    }
  }
}
