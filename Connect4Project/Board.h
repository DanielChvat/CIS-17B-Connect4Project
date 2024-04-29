


/* 
 * File:   Board.h
 * Author: Daniel
 *
 * Created on March 8, 2024, 11:28 AM
 */

#ifndef BOARD_H
#define BOARD_H

#include "Chip.h"
#include "Player.h"

#include <iostream>

using namespace std;

/* 3/16/24 Noel 
 */
class Board {

private:
    char **board;
    int connect;
    int rows;
    int cols;
    

public:
    Board();
    Board(int r, int c,int mode );
   
    void displayBoard()const;
    
    char **getBoard();
   
    bool valPlace(int col);
    
    /*
     * redefined function to return pointer to Player object below 
     */
    // char chkWin();
    
    Player *chkWin();
    
    //void plChip(int col, Chip  &chip);
    void plChip(int col, const Chip& chip);
    
    bool isColFull(int col);
    
    bool isBrdFull() const;
    
    bool isTie() const;
    
    void clearBoard();
    
    unsigned short getRows() const { return this->rows; };
    
    unsigned short getColmns() const { return this->cols; };
    
    unsigned short getMode() const { return this->connect; };
    
    void setMode();
    
    bool isTie();
    
    virtual ~Board();
    
    
};

#endif /* BOARD_H */
