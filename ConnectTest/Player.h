
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
class Player {
    private:
    Chip chip; 
    
public:
    Player();
  
//    Player( Chip c);
    
    Player(const Chip &c);
    
    virtual ~Player();

    int tkTurn(int cols);
    
    Chip getChip()const ;
};

#endif /* PLAYER_H */

