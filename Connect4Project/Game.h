

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
#include "Containers.h"

#include <functional>
#include <utility>

class add_player_exception : std::exception {
  const char* what() const noexcept override { return "Cannot add players during game."; }
};

//! Encapsulates Connect4 game logic
class Game {
private:
  struct Settings {

    unsigned short numP = 0; // Number of players
    unsigned short mode = 4; // Number of connected chips required to win
  } settings_;

  GameStateQueue stateQueue_;

  bool running_ = false;
  unsigned int turns_ = 0; // Turns taken since the start of the game
  Board *b_ = nullptr;
  Player **p_ = nullptr; // Array of players
  unsigned short pIdx_ = 0; // Index of current player
  int winIdx = -1; // Index of the winning player

  std::function<void(const Player*)> win_callbacks[64];
  unsigned short win_callbacks_size = 0;

  void raise_win_event(const Player* player) {
    for (size_t i=0; i < win_callbacks_size; i++) {
      win_callbacks[i](player);
    }
  }

  //! Enqueue the next state
  void queueState(GameState* state) { stateQueue_.push(state); }

public:

	Game();
	~Game();

	void run() noexcept;

  /** Add a player to the game. Cannot be called during a game.
   *
   * Used to add players to the game before the game session starts or after a game session ends.
   * If the player array is not empty, such as after a call to this function, the game will skip player setup.
   * Throws an exception if a game is currently running.
   * @param player Player instance to be added to the game.
   */
  void addPlayer(Player &player);

  /** Registers callback to be called when win event is raised.
   *
   * The win event is raised when a player wins and the game ends. The winning player is passed as an argument.
   * @param callback Function object to be called when a player wins.
   * @return Pointer to registered callback
   */
  const std::function<void(const Player*)>* registerWinCallback(std::function<void(const Player*)> callback) noexcept {
    win_callbacks[win_callbacks_size++] = std::move(callback);
    return &win_callbacks[win_callbacks_size];
  }

  /** Searches for Player with Chip color matching c.
   *
   * @param c Player's Chip color
   * @return Player or nullptr if no Player has Color c
   */
  Player* getPlayer(char c) const noexcept;

  Player* getCurPlayer() const noexcept { return p_[pIdx_]; }

  const Settings* getSettings() const noexcept { return &settings_; }

  // GameState classes must be friends to access private members
  friend SetupState;
  friend TurnState;
  friend EndState;
};

#endif /* GAME_H */