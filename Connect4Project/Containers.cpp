/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Containers.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on March 21, 2024, 1:38 AM
 */

#include "Containers.h"

GameStateQueue::~GameStateQueue() {
  while(!empty()) {
    delete pop();
  }
}

void GameStateQueue::push(GameState* state) {
  Element *elem = new Element {state};
  if (empty()) {
    front_ = back_ = elem;
  } else {
    back_->next = elem;
    back_ = back_->next;
  }
}

GameState* GameStateQueue::pop() {
  if (empty()) return nullptr;

  Element* elem = front_;
  GameState* state = elem->state;
  if (front_ == back_) back_ = nullptr;
  front_ = elem->next;
  delete elem;
  return state;
}

bool GameStateQueue::empty() {
  return front_ == nullptr;
}