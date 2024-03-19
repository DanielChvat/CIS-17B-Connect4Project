/* 
 * File:   Board.cpp
 * Author: Daniel
 * 
 * Created on March 8, 2024, 11:28 AM
 */
/*
 * Current implementation can handle these configurations:
 *      Connect 4(r x c): 6 x 7
 *      Connect 5(r x c): 7 x 8
 *      Connect 6(r x c): 8 x 9
 *      Connect 7(r x c): 9 x 10
 * Any larger and board would need to be reformatted for displaying purposes 
 * the game logic as is can handle ANY size board and any connect mode!!!!
 */
#include "Board.h"
#include <iomanip>
using namespace std;
/*
 3 param constructor: 
 *  3/16/24 Noel Perez
 */
Board::Board(int r, int c, int mode){
    this->connect =mode;
    this->rows =r;
    this->cols=c;
    
    board = new char*[rows];
    
    for(int i(0); i < rows; i++){
        board[i] = new char[cols];
        for(int j(0); j < cols; j++){
            board[i][j] = ' ';
        }
    }
}
    
// Destructor
/* 3/16/24 Noel Perez
 */
Board::~Board() {
    for (int i =0; i < rows; i++){
        delete []board[i];
    }
    delete[]board; 
}

// Function to display board dynamically based on mode 
/* 3/16/24 Noel Perez
 */
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
/* 3/16/24 Noel Perez
 */
 char**::Board::getBoard(){
     return board; 
 }

// Function definition for placing chip in column  
 /* 3/16/24 Noel Perez
 */
 void::Board::plChip(int column, const Chip& chip) {
     
     --column;

        for (int i = rows - 1; i >= 0; i--) {
            if (board[i][column] == ' ') {
                board[i][column] = chip.getColor();
                break;
            }
        }
 }
     
 
 // Function definition for validating column placement
 /* 3/16/24 Noel Perez
 */
 bool::Board::valPlace(int column ){
     --column;
    while (column < 0 || column >= cols || board[0][column] != ' ') {
        cout << "Invalid column selection. Please enter a valid column number"<<" (1-"<<this->cols<<"): ";
        cin >> column;
    }
    return true; 
 }
 
 //Temporary Input Validation (Moved the user input to main so this validation works for computer too)
 bool::Board::tempVal(int column){
     column--;
     if(column < 0 || column >= cols || board[0][column] != ' '){
         return false;
     }
     return true;    
 }
 
/* 3/16/24 Noel Perez
 * Function to check board winning conditions: returns char of winner if there is a winner
 * otherwise it returns '0' indicating no winner yet
 */
 char::Board::chkWin(){
     
       // Check for all winning conditions
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] != ' ') {
                    // Check vertical
                    if (i + connect <= rows) {
                        bool win = true;
                        for (int k = 1; k < connect; k++) {
                            if (board[i + k][j] != board[i][j]) {
                                win = false;
                                break;
                            }
                        }
                        if (win) return board[i][j];
                    }

                    // Check horizontal
                    if (j + connect <= cols) {
                        bool win = true;
                        for (int k = 1; k < connect; k++) {
                            if (board[i][j + k] != board[i][j]) {
                                win = false;
                                break;
                            }
                        }
                        if (win) return board[i][j];
                    }

                    // Check diagonal top-left to bottom-right
                    if (i + connect <= rows && j + connect <= cols) {
                        bool win = true;
                        for (int k = 1; k < connect; k++) {
                            if (board[i + k][j + k] != board[i][j]) {
                                win = false;
                                break;
                            }
                        }
                        if (win) return board[i][j];
                    }

                    // Check diagonal top-right to bottom-left
                    if (i + connect <= rows && j - connect + 1 >= 0) {
                        bool win = true;
                        for (int k = 1; k < connect; k++) {
                            if (board[i + k][j - k] != board[i][j]) {
                                win = false;
                                break;
                            }
                        }
                        if (win) return board[i][j];
                    }
                }
            }
        }

        return '\0'; // No winner 
    }

/*Function definition to check if columns on board are full
  */
    bool::Board::isColFull(int col) {
        --col;
        for (int i = 0; i < this->rows; i++) {
            if (board[i][col] == ' ') {  // ' ' is empty on board
                return false;  
            }
        }
        cout<<"COLUMN IS FULL!"<<endl;
        return true;  // All columns full
    }
    
/* Function definition for checking if board is full used for DRAW condition 
 */
    bool::Board::isBrdFull() const{
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                if (board[i][j] == ' ') {  
                    return false;  
                }
            }
        }
        cout<<"BOARD IS FULL!"<<endl;
        return true;  //  board is full
    }
     
 
