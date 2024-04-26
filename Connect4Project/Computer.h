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
class Computer: public Player{
    private:
    public:
        Computer();
        Computer(Chip &);
        int rTurn(Board *);
        virtual int tkTurn(Board *b) override {return cTurn(b);}
        int cTurn(Board *);
        int checkH(Board *,int); 
        int checkV(Board *,int);
        int checkD(Board *,int);
};


#endif /* COMPUTER_H */