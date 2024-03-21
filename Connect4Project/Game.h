

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
#include "GameStates.h"

class Game {
private:
  struct Settings {
    // Board size TODO board should store and have getters for these
    unsigned short rows = 0;
    unsigned short cols = 0;

    unsigned short numP = 2; // Number of players
    unsigned short mode = 4; // Number of connected chips required to win
  } settings_;

  enum STATES { SETUP, TURN, END };

  GameState* states_[3] = {new SetupState(this), new TurnState(this), new EndState(this)};
  // TODO GameState queue?
  GameState *curState_ = states_[0];
  GameState *nextState_ = nullptr;

  bool end_ = false;
  unsigned int turns_ = 0; // Turns taken since the start of the game
  Board *b_ = nullptr;
  Player **p_ = nullptr; // Array of players
  unsigned short pIdx_ = 0; // Index of current player
  int winIdx = -1; // Index of the winning player

  GameState* getState(STATES state) const { return states_[state]; }

public:
	Game() =default;
	~Game();

	void run();

  /** Searches for Player with Chip color matching c.
   *
   * @param c Player's Chip color
   * @return Player or nullptr if no Player has Color c
   */
  Player* getPlayer(char c) const;

  Player* getCurPlayer() const { return p_[pIdx_]; }

  const Settings* getSettings() const { return &settings_; }

  friend SetupState;
  friend TurnState;
  friend EndState;
};

#endif /* GAME_H */

