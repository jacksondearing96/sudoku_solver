#include "Player.h"

#include <iostream>
#include <vector>
#include <stack>

#include "Drawer.h"

using namespace std;

Player::Player(std::shared_ptr<Game> game_) :
  game(game_), changeMade(true), contradiction(false) {
}

void Player::playGame() {

    Drawer::Draw(game->board->getState());
  clock_t tStart = clock();
  changeMade = true;

  while (changeMade) {
    changeMade = false;
    contradiction = false;
    fillEmpties();

    if (contradiction)
      break;
  }

  if (game->board->countEmpties() == 0) {
    game->finishedState = game->board->getState();
    //printf("Completed in: %.6fseconds\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

  } else {

    if (contradiction) {
      backTrack();
    } else {
      makeGuess();
    }

    playGame();
  }

}

void Player::fillEmpties() {

  vector<int> missingNums;
  vector<Position> possiblePositions;
  int row, col;

  for (int i=0 ; i<3 ; i++) {
    for (int j=0 ; j<3 ; j++) {
      missingNums = game->board->squares[i][j].getMissingNums();

      for (int k=0 ; k<missingNums.size() ; k++) {
        possiblePositions = game->board->squares[i][j].getPossiblePositionsForNum(missingNums.at(k));

        if (possiblePositions.size() == 0) {
          contradiction = true;
          Drawer::HighlightContradiction(i, j);
          return;
        }

        if (possiblePositions.size() == 1) {

          row = possiblePositions.at(0).row;
          col = possiblePositions.at(0).col;
          game->board->squares[i][j].data[row][col] = missingNums.at(k);
          changeMade = true;
          Drawer::Draw(game->board->getState());
        }
      }
    }
  }
}

void Player::makeGuess() {

  int minimumOptions = 2;
  while (true) {
    for (int i=0 ; i<3 ; i++) {
      for (int j=0 ; j<3 ; j++) {
        vector<int> missingNums = game->board->squares[i][j].getMissingNums();

        for (int k=0 ; k<missingNums.size() ; k++) {
          vector<Position> possiblePositions = game->board->squares[i][j].getPossiblePositionsForNum(missingNums.at(k));

          if (possiblePositions.size() == minimumOptions) {

            int guessRow = possiblePositions.at(0).row;
            int guessCol = possiblePositions.at(0).col;
            possiblePositions.erase(possiblePositions.begin());


            game->board->squares[i][j].data[guessRow][guessCol] = missingNums.at(k);

            GameState newState = GameState(game->board->getState(),
                                           game->board->squares[i][j].position,
                                           missingNums.at(k),
                                           Position(guessRow, guessCol),
                                           possiblePositions);

            game->gameStates.push(newState);
            return;
          }
        }
      }
    }
    minimumOptions++;
  }
}

void Player::backTrack() {
  contradiction = false;

  GameState gameState = game->gameStates.top();
  game->gameStates.pop();

  if (gameState.alternativePositions.size() == 0) {
    backTrack();

  } else {

    game->board->reassignState(gameState.state);

    Drawer::DrawBackTrack(game->board->getState());

    int squareRow = gameState.squarePosition.row;
    int squareCol = gameState.squarePosition.col;
    int dataRow = gameState.guessedPosition.row;
    int dataCol = gameState.guessedPosition.col;

    game->board->squares[squareRow][squareCol].data[dataRow][dataCol] = 0;

    int newGuessRow = gameState.alternativePositions.at(0).row;
    int newGuessCol = gameState.alternativePositions.at(0).col;


    game->board->squares[squareRow][squareCol].data[newGuessRow][newGuessCol] = gameState.guessNum;
    gameState.alternativePositions.erase(gameState.alternativePositions.begin());

    game->gameStates.push(gameState);
  }
}
