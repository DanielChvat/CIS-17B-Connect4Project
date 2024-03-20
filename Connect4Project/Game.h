

/* 
 * File:   Game.h
 * Author: Daniel
 *
 * Created on March 8, 2024, 11:30 AM
 */

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

enum class GameState {
	Player_1, Player_2
};

class Game {
private:
	Player *p1;
	Player *p2;
	Board *b;
	GameState gs;
	/* Computer *c; */


	void init(int, int, int, char, char);
public:
	Game(int, int, int, char, char);
	~Game();
	void run(int);
};

#endif /* GAME_H */

