/* 
 * File:   Computer.h
 * Author: michaelsalib
 *
 * Created on March 17, 2024
 */

//User Libraries
#include "Chip.h"
#include "Board.h"

#include <thread>
#include <chrono>


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
        

void delayOutput( int delaySec) {
    cout<<"Computer is thinking..."<<endl;
    this_thread::sleep_for(chrono::seconds(delaySec));
}
};


#endif /* COMPUTER_H */
