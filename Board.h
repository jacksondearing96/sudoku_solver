#ifndef BOARD_H
#define BOARD_H

#include "Position.h"
#include "Square.h"

#include <vector>

using namespace std;

class Board {

public:

  Board(int** State);
  int** getState();

  int countEmpties();

  int** state;
  Square** squares;

  void reassignState(int** State);

};

#endif
