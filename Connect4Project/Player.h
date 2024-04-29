
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

/* 3/16/24 Noel Perez
 */

class Board;

class Player {
protected:
    Chip chip; 
    
public:
    Player();
  
//    Player( Chip c);
    
    Player(const Chip &c);
    
    virtual ~Player();

    virtual int tkTurn(Board *);
    
    Chip getChip()const ;
};

#endif /* PLAYER_H */