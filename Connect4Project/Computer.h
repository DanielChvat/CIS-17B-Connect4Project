/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Computer.h
 * Author: michaelsalib
 *
 * Created on March 17, 2024
 */

//User Libraries
#include "Chip.h"

#ifndef COMPUTER_H
#define COMPUTER_H
class Computer{
    private:
        Chip chip;
    public:
        Computer();
        int rTurn(int);
        Chip getChip();
};


#endif /* COMPUTER_H */

