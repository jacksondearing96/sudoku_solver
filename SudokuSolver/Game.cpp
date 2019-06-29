#include "Game.h"
#include "Board.h"

#include <iostream>
#include <string>

using namespace std;


Game::Game(int** initialState) {
	board = new Board(initialState);
}
