/* 
 * File:   Computer.h
 * Author: michaelsalib
 *
 * Created on March 17, 2024
 */

//User Libraries
#include "Chip.h"
#include "Board.h"

#ifndef COMPUTER_H
#define COMPUTER_H
class Computer{
    private:
        Chip chip;
    public:
        Computer();
        int rTurn(int);
        Chip getChip();
        int cTurn(Board &,int);
        int checkH(Board &); 
        int checkV(Board &);
        int checkD(Board &);
        int build(Board &); //Not yet implemented
};


#endif /* COMPUTER_H */
