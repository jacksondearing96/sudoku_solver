#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"
#include <memory>

class Player {
public:

  Player(std::shared_ptr<Game>);

  std::shared_ptr<Game> game;

  void playGame();

  bool changeMade;
  bool contradiction;

  void fillEmpties();
  void makeGuess();
  void backTrack();

};

#endif
