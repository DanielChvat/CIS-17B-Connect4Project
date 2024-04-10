/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Chip.cpp
 * Author: danielchvat
 * 
 * Created on March 11, 2024, 2:56 PM
 */

#include "Chip.h"

/* 3/16/24 Noel
 * 
 * Default constructor calls setColor function to set color of chip: 
 * does input validation
 */
Chip::Chip() {
    Chip::setColor();
}
/* 3/16/24 Noel 
 * 
 * One param constructor takes in char 
 */
Chip::Chip(char c){
    this->color = c; 
}



Chip::~Chip() {
}

// Function that returns the chip color
/* 3/16/24 Noel 
 */
char::Chip::getColor() const {
    return this->color;
}

void::Chip:: setColor(){
         char choice;
        bool valid = false;
        while ( !valid ) {
            cout << "Enter a character for the chip color (a-z): ";
            cin >> choice;
            choice = toupper(choice);
            if ( (choice >= 'A' and choice <= 'Z') or (choice >= 'a' and choice <= 'z') ){
                this->color = choice;
                
                valid = true;
            } else {
                cerr << "Error: Invalid color. Re-enter a letter.\n";
               
                while ( cin.get() != '\n') ;
            }
        }
}