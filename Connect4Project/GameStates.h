/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   GameStates.h
 * Author: Theopolis Armstrong
 *
 * Created on March 20, 2024, 2:49 PM
 */

#ifndef GAMESTATES_H
#define GAMESTATES_H

#include "Player.h"

class Game;

//! Encapsulates a Game state machine's state
class GameState {
public:
    GameState(Game *game) : game_(game) { }
    virtual ~GameState() = default;

    virtual void Enter() { }
    virtual void Run() { }
protected:
    Game *game_;
};

/** Encapsulates pre-game setup logic.
 *
 * Defaults to 2 players and runs player setup if the player array is empty.
 */
class SetupState : public GameState {
public:
    SetupState(Game *game) : GameState(game) { }
    void Run() override;
private:
    void setupPlayers();
    void setupBoard();
};

/** Encapsulates logic of a single turn during the game.
 *
 * Win checks assume win conditions are not met at the start of the turn.
 */
class TurnState : public GameState {
public:
  TurnState(Game *game) : GameState(game) { }
  void Enter() override;
  void Run() override;
};

//! Encapsulates post-game logic.
class EndState : public GameState {
public:
  EndState(Game *game) : GameState(game) { }
  void Run() override;
};

#endif /* GAMESTATES_H */