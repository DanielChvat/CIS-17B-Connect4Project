/* File: Computer.cpp
 * Author: michaelsalib
 * Created on: March 17, 2024
 * 
 */
        
//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Computer.h"

//Functions

//Constructor
Computer::Computer(){
    this->chip='C';
}

Computer::Computer(Chip &c):Player(c){
    
}

//Random Turn Function
int Computer::rTurn(Board *b){
    int size=b->getColmns();
    int column;
    //Random column based on board size (size = number of columns)
    column=rand()%size+1;
 
    return column;
}

//Pre-Win Check, for computer to block player wins or finish connect
int Computer::cTurn(Board *b){
    Computer::delayOutput(rand()%2 + 1); 
    const int mode=b->getMode();
    for(int i=(mode-1); i>2; i--){
        //Horizontal
        if(checkH(b,i)!=-1){
            //cout<<"H"<<endl;
            return checkH(b,i);
        }
        //Vertical
        if(checkV(b,i)!=-1){
            //cout<<"V"<<endl;
            return checkV(b,i);
        }
        //Diagonal
        if(checkD(b,i)!=-1){
            //cout<<"D"<<endl;
            return checkD(b,i);
        }
    }

    //Random
    //cout<<"R"<<endl;
    return (rTurn(b));

}

//Checking Horizontal Pre-win
int Computer::checkH(Board *board,int num){
   //Copying private board info with getters
   char **b = board->getBoard();
   const int mode=board->getMode();
   const int rows=board->getRows();
   const int cols=board->getColmns();
   int tracker=1,begin,end,select;
   
   //Looping through board
   for(int i=0; i<rows; i++){
       for(int j=0; j<cols; j++){
           //If two adjacent slots are the same and not empty
           if(j<cols-1 && b[i][j]==b[i][j+1] && b[i][j]!=' '){ 
               if(tracker==1){  
                   begin=j; //Tracking first chip of sequence
               }
               tracker++; //Incrementing for each identical adjacent chip
               if(tracker==num){
                   end=j+1; //Tracking last element of sequence
                   
                   //If there are open slots on either side of sequence
                   //And if there are chips directly under those slots
                   //(cannot be last row or else checking out of bounds)
                   if(i<rows-1 && b[i][begin-1]==' ' && b[i+1][begin-1]!=' '){
                       select=begin;
                       return select;
                   }
                   if(i<rows-1 && b[i][end+1]==' ' && b[i+1][end+1]!=' '){
                       select=end+2;
                       return select; 
                   }
                   
                   //If it's the last row, only check left and right sides
                   if(i==rows-1 && b[i][begin-1]==' '){
                       select=begin; //Left side
                       return select;
                   }
                   if(i==rows-1 && b[i][end+1]==' '){
                       select=end+2; //Right Side
                       return select;  
                   }
               }
           }
           //Resetting tracker when adjacent slots don't match or are empty
           else{
               tracker=1;
           }
       }
   } 
   return -1;
}

//Checking Vertical Pre-win
int Computer::checkV(Board *board,int num){
   //Copying private board info with getters
   char **b = board->getBoard();
   const int mode=board->getMode();
   const int rows=board->getRows();
   const int cols=board->getColmns();
   int tracker=1;
   
   
   for(int j=0; j<cols; j++){
       for(int i=rows-1; i>0; i--){
           for(int k=1; k<mode && i-k>=0; k++){
               //Iterating vertically through each column
               if(b[i][j]!=' ' && b[i][j]==b[i-k][j] && i-k<rows){
                   tracker++;
                   //If the slot above the sequence is open
                   if(tracker==num && b[i-num][j]==' '){
                       return j+1;
                   }
               }
           }
           tracker=1;
       }
    }
   
   return -1;
}

int Computer::checkD(Board *board,int num){
    //Copying private board info with getters
    char **b = board->getBoard();
    const int mode=board->getMode();
    const int rows=board->getRows();
    const int cols=board->getColmns();
    int tracker=1, left,right;
   
    //Checking top-half / diagonals
    for(int i=rows-1; i>=mode; i--){
        for(int j=0; j<i; j++){
            //If next diagonal is matching and not empty
            if(b[i-j][j]==b[i-(j+1)][j+1] && b[i-j][j]!=' '){
                tracker++;
                //If sequence is one-from winning
                if(tracker==num){
                    //Checking right side
                    //If next column is valid
                    if(i-j-1>=0 && j+1<cols){
                        //If next in sequence is open and has chip underneath
                        if(b[i-j-2][j+2]==' ' && b[i-j-1][j+2]!=' '){
                            right=j+2;
                            return right+1;
                        }
                    }
                    
                    //Checking left side of diagonal
                    //Boundary check and not last diagonal
                    if(i-j+(num-1)<rows-1 && j-(num-1)>=0){
                        if(b[i-j+(num-1)][j-(num-1)]==' ' && b[i-j+num][j-(num-1)]!=' '){
                            left=j-(num-1);
                            return left+1;
                        }
                    }
                    //Last row doesn't need to check for chip beneath it
                    if(i-j+(num-1)==rows-1 && j-(num-1)>=0){
                        if(b[i-j+(num-1)][j-(num-1)]==' '){
                            left=j-(num-1);
                            return left+1;
                        }
                    }
                }
            }
            else{
                tracker=1;
            }
        }
    }
    
    //Checking bottom-half / diagonals
    for(int j=1; j<cols-1; j++){
        int i=rows-1;
        for(int k=0; j+k<cols-1; k++){
            //Checking next diagonal
            if(b[i-k][j+k]!=' ' && b[i-k][j+k]==b[i-(k+1)][j+k+1]){
                tracker++;
                //One from winning
                if(tracker==num){
                    //Checking right side of diagonal
                    //If within bounds
                    if(i-(k+2)>=0 && j+k+2<=cols-1){
                        //If next diagonal is empty & slot below is not empty
                        if(b[i-(k+2)][j+k+2]==' ' && b[i-(k+1)][j+k+2]!=' '){
                            right=j+k+3;
                            return right;
                        }
                    }
                 
                    //Checking left side of diagonals
                    //If above last row & within bounds
                    if(i-k+(num-1)<rows-2 && j+k-(num-1)>0){
                        //Loop stops 2 elements early, so mode-2
                        //Checking if diagonal to the bottom left is open, and underneath is filled
                        if(b[i+(num-1)][j-(num-1)]==' ' && b[i+num][j-(num-1)]!=' '){
                            left=j+k-(num-1);
                            return left+1;
                        }
                    }
                    //If last row and within bounds
                    if(i-k+(num-1)==rows-1 && j+k-(num-1)>0){
                        //If the bottom left of the sequence is open 
                        if(b[i-k+(num-1)][j+k-(num-1)]==' '){
                            left=j+k-(num-1); 
                            return left+1;
                        }
                    }
                }
            }
            else{
                tracker=1;
            }
        }
    }
    
    //Checking top-half \ diagonals
    for(int j=1; j<cols-1; j++){
        for(int k=0; j+k<cols-1; k++){
            //Checking one down and one right
            if(b[k][j+k]==b[k+1][j+k+1] && b[k][j+k]!=' '){
                tracker++;
                //One away from win
                if(tracker==num){
                    //Right side of diagonals
                    //Diagonals above last row
                    if(k+2<rows-1 && j+k+2<cols-1){
                        //If next diagonal is empty and has chip beneath
                        if(b[k+2][j+k+2]==' ' && b[k+3][j+k+2]!=' '){
                            right=j+k+2;
                            return right+1;
                        }
                    }
                    //Last row diagonal doesn't check for chip beneath
                    if(k+2==rows-1){
                        if(b[k+2][j+k+2]==' '){
                            right=j+k+2;
                            return right+1;      
                        }
                    }
                    //Left side of diagonals
                    if(k-(mode-2)>=0 && j+k-(mode-2)>0){
                        if(b[k-(num-1)][j+k-(num-1)]==' ' && b[k-(num-1)+1][j+k-(num-1)]!=' '){
                            left=j+k-(num-1);
                            return left+1;
                        }
                    }
                }
            }
            else{
                tracker=1;
            }
        }
    }
    
    //Checking bottom-half \ diagonals
    for(int i=0; i<rows-1; i++){
        for(int k=0; k+i<rows-1; k++){
            //One down and one right
            if(b[i+k][k]==b[i+k+1][k+1] && b[i+k][k]!=' '){
                tracker++;
                //One from win
                if(tracker==num){
                    //Right side of diagonals
                    //Diagonal above last row
                    if(i+k+2<rows-1 && k+2<cols-1){
                        //Checking next diagonal and slot beneath
                        if(b[i+k+2][k+2]==' ' && b[i+k+3][k+2]!=' '){
                            right=k+2;
                            return right+1;
                        }
                    }
                    //Diagonal on last row
                    if(i+k+2==rows-1 && k+2<cols-1){
                        //Only checking next diagonal on last row
                        if(b[i+k+2][k+2]==' '){
                            right=k+2;
                            return right+1;
                        }
                    }
                    
                    //Left side of diagonals
                    if(i+k-(num-1)>=0 && k-(num-1)>=0 && i+k-(num-1)+1<rows-1){
                        //Checking left of diagonal and if underneath has a chip
                        if(b[i+k-(num-1)][k-(num-1)]==' ' && b[i+k-(num-1)+1][k-(num-1)]!=' '){
                            left=k-(num-1);
                            return left+1;
                        }
                    }
                }
            }
            else{
                tracker=1;
            }
        }
    }
    

   return -1;
}
