/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Player.h
 * Author: Daniel
 *
 * Created on March 16, 2024, 6:01 PM
 */
#include "Chip.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player {
    private:
    Chip chip; 
    
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();

    int tkTurn();
    
    
};

#endif /* PLAYER_H */

