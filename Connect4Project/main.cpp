

/* 
 * File:   main.cpp
 * Author: Daniel
 *
 * Created on March 8, 2024, 10:07 AM
 */

#include <cstdlib>
#include <iostream>

#include "Board.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout << "Hello World" << endl;
    cout << "Test In Board Class" << endl;
    
    
    Board b = Board(6,7 ,4);
    
    cout<<"Connect 4 board"<<endl;
    b.displayBoard();
    
   
    
    Chip c;
    cout<<c.getChip()<<endl;
     b.plChip(1,c);
     
     b.displayBoard();
    char **b2 = b.getBoard();
    
    cout<<"Return board from pointer and modify"<<endl;  
    
    b2[5][0] = 'X';
    
   b.displayBoard();
//    
//    cout<<"Connect 5 board";
//    Board b3 = Board (7,8,5);
//    b3.displayBoard();
//    
//    cout<<"\nConnect 6 board";
//    Board b4 = Board(8,9,6);
//    b4.displayBoard();
    
    return 0;
}