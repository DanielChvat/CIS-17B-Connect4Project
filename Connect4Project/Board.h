


/* 
 * File:   Board.h
 * Author: Daniel
 *
 * Created on March 8, 2024, 11:28 AM
 */

#ifndef BOARD_H
#define BOARD_H

#include "Chip.h"

#include <iostream>

using namespace std;

/* 3/16/24 Noel Perez
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
    
    char chkWin();
    
    //void plChip(int col, Chip  &chip);
    void plChip(int col, const Chip& chip);
    
    virtual ~Board();
};

#endif /* BOARD_H */
