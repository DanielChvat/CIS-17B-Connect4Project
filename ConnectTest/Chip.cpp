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
 */
Chip::Chip() {
    this->color='P';
 
}
/* 3/16/24 Noel 
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