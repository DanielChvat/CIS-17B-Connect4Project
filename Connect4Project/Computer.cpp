/* File: Computer.cpp
 * Author: michaelsalib
 * Created on: March 17, 2024
 * 
 */
        
//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Computer.h"

//Functions

//Constructor
Computer::Computer(){
    this->chip='C';
}

//Get Function
Chip Computer::getChip(){
    return chip;
}

//Random Turn Function
int Computer::rTurn(int size){
    int column;
    //Random column based on board size (size = number of columns)
    column=rand()%size+1;
 
    return column;
}
