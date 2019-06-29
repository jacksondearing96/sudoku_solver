#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "Board.h"

#include <stack>

class Game {
public:
    Game(int** initialState);
	Board* board;

	std::stack<GameState> gameStates;

	int** finishedState;

};

#endif
