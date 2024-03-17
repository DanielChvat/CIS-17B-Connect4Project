

/* 
 * File:   Board.cpp
 * Author: Daniel
 * 
 * Created on March 8, 2024, 11:28 AM
 */
/*
 Notes: Connect 4(r x c): 6 x 7
 *      Connect 5(r x c): 7 x 8
 *      Connect 6(r x c): 8 x 9
 *       
 */
#include "Board.h"
#include <iomanip>
using namespace std;
/*
 3 param constructor: 
 */
Board::Board(int r, int c, int mode){
    this->connect =mode;
    this->rows =r;
    this->cols=c;
    
    board = new char*[rows];
    
    for(int i(0); i < rows; i++){
        board[i] = new char[cols];
        for(int j{0}; j < cols; j++){
            board[i][j] = ' ';
        }
    }
}
    
// Destructor
Board::~Board() {
    for (int i =0; i < rows; i++){
        delete []board[i];
    }
    delete[]board; 
}

// Function to display board dynamically based on mode 
void Board::displayBoard() const {
    cout << "\n";
    for (int i = 0; i < rows; i++) {
        cout<< "| ";
        for (int j = 0; j < cols; j++) {
            cout<< board[i][j] << " | ";
        }
        cout << endl;
    }

    // Display column numbers dynamically 
    cout << "+";
    for (int j = 0; j < cols; j++) {
        cout<< "---+";
    }
    cout << "\n";

    cout << "|";
    for (int j = 0; j < cols; j++) {
        cout<< " " << j + 1 << " |";
    }
    cout <<"\n";

    for(int j = 0; j < cols; j++)cout<<"----";
    cout<<"\n";
  
}
 // Get board function: return the board in its current state
 char**::Board::getBoard(){
     return board; 
 }