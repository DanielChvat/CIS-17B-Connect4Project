/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Game.cpp
 * Author: Daniel
 * 
 * Created on March 8, 2024, 11:30 AM
 */

#include "Game.h"
#include "Player.h"
#include "Chip.h"

Game::Game() {
  stateQueue_.push(new SetupState(this));
}

Game::~Game(){
  for (int i=0; i < getSettings()->numP; i++) {
    delete p_[i];
  }
  delete [] p_;
	delete b_;
}

void Game::run() noexcept {
  running_ = true;
  while (running_) {
    GameState* state = stateQueue_.pop();
    state->Enter();
    state->Run();
  }
}

void Game::addPlayer(Player &player) {
  if (running_) { throw add_player_exception(); }
  if (!p_) {
    // Create new player array
    settings_.numP = 1;
    p_ = new Player*[1];
    p_[0] = &player;
  } else {
    // Extend player array to fit new player
    Player **temp = p_;
    p_ = new Player*[settings_.numP+1];
    for (size_t i=0; i<settings_.numP; i++) {
      p_[i] = temp[i];
    }
    p_[settings_.numP++] = &player;
    delete [] temp;
  }


}

Player* Game::getPlayer(char c) const noexcept {
  for (int i=0; i < settings_.numP; i++) {
    if (p_[i]->getChip().getColor() == c) return p_[i];
  }
  return nullptr;
}