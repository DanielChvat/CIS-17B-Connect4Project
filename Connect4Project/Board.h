

/* 
 * File:   Board.h
 * Author: Daniel
 *
 * Created on March 8, 2024, 11:28 AM
 */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>

using namespace std;

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
    
    // function to check winner: needs to check horizontal, vertical and diagonal. Return type and Parameters?
    
    // function to place the chips or take turns : which ever makes more sense. Return type? and Parameters?
    
    // 
    
    virtual ~Board();
};

#endif /* BOARD_H */

