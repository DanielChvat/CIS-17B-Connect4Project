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

Chip::Chip() {
    this->color='P';
    
}

Chip::Chip(const Chip& orig) {
}

Chip::~Chip() {
}

// Function that returns the chip color
char Chip::getChip(){
    return this->color;
}