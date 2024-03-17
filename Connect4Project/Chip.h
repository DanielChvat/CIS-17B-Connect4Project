

/* 
 * File:   Chip.h
 * Author: danielchvat
 *
 * Created on March 11, 2024, 2:56 PM
 */

#ifndef CHIP_H
#define CHIP_H

class Chip {
private:
    char color;
    
    public:
    Chip();
    Chip(const Chip& orig);
    virtual ~Chip();
public: 
    char getChip();
    
};

#endif /* CHIP_H */

