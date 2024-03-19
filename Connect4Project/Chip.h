

/* 
 * File:   Chip.h
 * Author: danielchvat
 *
 * Created on March 11, 2024, 2:56 PM
 */

#ifndef CHIP_H
#define CHIP_H

/* 3/16/24 Noel Perez
 */
class Chip {
private:
    char color;
    
public:
    Chip();
    Chip(char c);
  
    virtual ~Chip();
public: 
    char getColor() const ;
    
};

#endif /* CHIP_H */
