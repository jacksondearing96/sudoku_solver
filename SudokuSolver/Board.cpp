#include "Board.h"
#include "Square.h"
#include "Position.h"

#include <iostream>

using namespace std;

void allocateRelatedSquares(Square** squares) {

  vector<Square> horizontallyRelatedSquares;
  vector<Square> verticallyRelatedSquares;

  for (int i=0 ; i<3 ; i++) {
    for (int j=0 ; j<3 ; j++) {

      // set the vertically related squares
      for (int k=0 ; k<3 ; k++) {
        if (i != k) {
          verticallyRelatedSquares.push_back(squares[k][j]);
        }
      }

      // set the horizontally reltated squares
      for (int m=0 ; m<3 ; m++) {
        if (j != m) {
          horizontallyRelatedSquares.push_back(squares[i][m]);
        }
      }

      squares[i][j].setVerticallyRelatedSquares(verticallyRelatedSquares);
      squares[i][j].setHorizontallyRelatedSquares(horizontallyRelatedSquares);
      verticallyRelatedSquares.clear();
      horizontallyRelatedSquares.clear();

    }
  }
}

Board::Board(int** State) :
  state(State)
{
  squares = new Square*[3];

  for (int i=0 ; i<3 ; i++) {

    squares[i] = new Square[3];

    for (int j=0 ; j<3 ; j++) {
      squares[i][j].setPosition(Position(i,j));

      for (int k=0 ; k<3 ; k++) {
        for (int m=0 ; m<3 ; m++) {
          squares[i][j].data[k][m] = state[i*3 + k][j*3 + m];
        }
      }
    }
  }

  allocateRelatedSquares(squares);
}

int** Board::getState() {
  for (int i=0 ; i<3 ; i++) {
    for (int j=0 ; j<3 ; j++) {
      for (int k=0 ; k<3 ; k++) {
        for (int m=0 ; m<3 ; m++) {
          state[i*3 + k][j*3 + m] = squares[i][j].data[k][m];
        }
      }
    }
  }
  return state;
}


int Board::countEmpties() {
  int count = 0;

  for (int i=0 ; i<3 ; i++) {
    for (int j=0 ; j<3 ; j++) {
      for (int k=0 ; k<3 ; k++) {
        for (int m=0 ; m<3 ; m++) {
          if (squares[i][j].data[k][m] == 0)
            count++;
        }
      }
    }
  }
  return count;
}

void Board::reassignState(int** state_) {
  state = state_;

  for (int i=0 ; i<3 ; i++) {
    for (int j=0 ; j<3 ; j++) {
      for (int k=0 ; k<3 ; k++) {
        for (int m=0 ; m<3 ; m++) {
          squares[i][j].data[k][m] = state[i*3 + k][j*3 + m];
        }
      }
    }
  }
}
