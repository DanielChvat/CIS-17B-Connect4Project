/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Containers.h
 * Author: Theopolis Armstrong
 *
 * Created on March 21, 2024, 1:38 AM
 */

#ifndef CONTAINERS_H
#define CONTAINERS_H

#include "GameStates.h"

class GameStateQueue {
public:
  ~GameStateQueue();

  void push(GameState* state);
  GameState* pop();
  bool empty();

private:
  struct Element {
    GameState *state = nullptr;
    Element *next = nullptr;
  };

  Element *front_ = nullptr;
  Element *back_ = nullptr;
};

#endif /* CONTAINERS_H */

