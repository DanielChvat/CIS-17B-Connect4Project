

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
#include "Computer.h"

class Game {
private:
   // Board b;
   // Player p;
//    Computer c;
    
  //  enum class GameState = {"playerTurn" , "compTurn"};
    
  public:
    Game();
 
    virtual ~Game();    
    
    void runGame();
    
};

#endif /* GAME_H */

