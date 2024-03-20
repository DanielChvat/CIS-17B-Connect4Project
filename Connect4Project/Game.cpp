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
#include "Chip.h"

Game::Game(int rows, int cols, int mode, char color1, char color2){
    init(rows, cols, mode, color1, color2);
}

Game::~Game(){
	delete p1;
	delete p2;
	delete b;
}

void Game::init(int rows, int cols, int mode, char color1, char color2){
    Chip red = Chip(color1);
    Chip blue = Chip(color2);

    b = new Board(rows, cols, mode);	
    p1 = new Player(red);
    p2 = new Player(blue);
}

void Game::run(int cols){
    gs = GameState::Player_1;

    while (true) {
        b->displayBoard();

        Player *crrntPlyr = (gs == GameState::Player_1) ? p1 : p2;

        cout << "Current turn: ";
        (gs == GameState::Player_1) ? cout << "Player 1"<<endl : cout<<"Player 2"<<endl;
       
        int column = crrntPlyr->tkTurn(cols);
       

        if (b->valPlace(column) && !b->isColFull(column)) {
           b->plChip(column, crrntPlyr->getChip());

           char winner = b->chkWin();

           if (winner != '\0') {
               b->displayBoard();

               if (gs == GameState::Player_1) {
                   cout << "Player 1 wins" << endl;
               } else {
                   cout << "Player 2 wins" << endl;
               }
               break;
           } else if (b->isBrdFull()) {
               b->displayBoard();
               cout << "DRAW!" << endl;
               break;
           }
       }
    gs = (gs == GameState::Player_1) ? GameState::Player_2 : GameState::Player_1;
    }
}
