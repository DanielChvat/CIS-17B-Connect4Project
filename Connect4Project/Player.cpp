
/* 
 * File:   Player.cpp
 * Author: Daniel
 * 
 * Created on March 16, 2024, 6:01 PM
 */
#include <iostream>
#include "Player.h"
#include "Board.h"

/* 3/16/24 Noel Perez
 * 
 * default Player constructor calls default Chip constructor to set Player's chip color 
 */
Player::Player() {
    this->chip = Chip();
    this->won = false;
}

/* 1 param constructor takes in Chip object
 */
 Player::Player(const Chip &c) :  chip(c){
     this->won = false;
 }
/* 3/16/24 Noel Perez
 */
//Player::Player( Chip c) {
//    this->chip = c; 
//}


Player::~Player() {
}

//get chip function
/* Noel 3/16/24
 */
Chip Player::getChip() const {
    return chip;
}

/*Function definition for player to take turn with input validation
 * Noel 3/16/24
 */
int::Player::tkTurn(Board *b){
    int cols= b->getColmns();
     int column=0;
        bool validInput = false;

        while (!validInput) {
            cout << "Enter column number (1-" << cols << "): ";
            if (!(cin >> column)) {
                cin.clear(); 
                cin.ignore(100, '\n'); 
                cout << "Invalid input. Please enter a number." << endl;
            } else if (column < 1 || column > cols) {
                cout << "Column number must be between 1 and " << cols << "." << endl;
            } else {
                validInput = true;
            }
        }

        return column;
    }