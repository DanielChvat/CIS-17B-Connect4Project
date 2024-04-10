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

void Game::run() {
  while (!end_) {
    GameState* state = stateQueue_.pop();
    state->Enter();
    state->Run();
  }
}

Player* Game::getPlayer(char c) const {
  for (int i=0; i < settings_.numP; i++) {
    if (p_[i]->getChip().getColor() == c) return p_[i];
  }
  return nullptr;
}