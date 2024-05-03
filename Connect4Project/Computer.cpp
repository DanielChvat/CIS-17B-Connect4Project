/* File: Computer.cpp
 * Author: michaelsalib
 * Created on: March 17, 2024
 * 
 */
        
////System Libraries
//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//using namespace std;
//
////User Libraries
//#include "Computer.h"
//
////Functions
//
////Constructor
//Computer::Computer(){
//    this->chip='C';
//}
//
////Get Function
//Chip Computer::getChip(){
//    return chip;
//}
//
////Random Turn Function
//int Computer::rTurn(int size){
//    int column;
//    //Random column based on board size (size = number of columns)
//    column=rand()%size+1;
// 
//    return column;
//}
//
////Pre-Win Check, for computer to block player wins or finish connect
//int Computer::cTurn(Board &b,int size){
//    //Horizontal
//    if(checkH(b)!=-1){
//        //cout<<"H"<<endl;
//        return checkH(b);
//    }
//    //Vertical
//    if(checkV(b)!=-1){
//        //cout<<"V"<<endl;
//        return checkV(b);
//    }
//    //Diagonal
//    //if(checkD(b)!=-1){
//    //    cout<<"D"<<endl;
//    //    return checkD(b);
//    //}
//    //Random
//    else{
//        cout<<"R"<<endl;
//        return (rTurn(size));
//    }
//
//}
//
////Checking Horizontal Pre-win
//int Computer::checkH(Board &board){
//   //Copying private board info with getters
//   char **b = board.getBoard();
//   const int mode=board.getMode();
//   const int rows=board.getRows();
//   //const int cols=board.getCols();
//   int tracker=1,begin,end,select;
//   
//   //Looping through board
//   for(int i=0; i<rows; i++){
//       for(int j=0; j<cols; j++){
//           //If two adjacent slots are the same and not empty
//           if(j<cols-1 && b[i][j]==b[i][j+1] && b[i][j]!=' '){ 
//               if(tracker==1){  
//                   begin=j; //Tracking first chip of sequence
//               }
//               tracker++; //Incrementing for each identical adjacent chip
//               if(tracker==mode-1){
//                   end=j+1; //Tracking last element of sequence
//                   
//                   //If there are open slots on either side of sequence
//                   //And if there are chips directly under those slots
//                   //(cannot be last row or else checking out of bounds)
//                   if(i<rows-1 && b[i][begin-1]==' ' && b[i+1][begin-1]!=' '){
//                       select=begin;
//                       return select;
//                   }
//                   if(i<rows-1 && b[i][end+1]==' ' && b[i+1][end+1]!=' '){
//                       select=end+2;
//                       return select; 
//                   }
//                   
//                   //If it's the last row, only check left and right sides
//                   if(i==rows-1 && b[i][begin-1]==' '){
//                       select=begin; //Left side
//                       return select;
//                   }
//                   if(i==rows-1 && b[i][end+1]==' '){
//                       select=end+2; //Right Side
//                       return select;  
//                   }
//               }
//           }
//           //Resetting tracker when adjacent slots don't match or are empty
//           else{
//               tracker=1;
//           }
//       }
//   } 
//   return -1;
//}
//
////Checking Vertical Pre-win
//int Computer::checkV(Board &board){
//   //Copying private board info with getters
//   char **b = board.getBoard();
//   const int mode=board.getMode();
//   const int rows=board.getRows();
//   //const int cols=board.getCols();
//   int tracker=1;
//   
//   
//   for(int j=0; j<cols; j++){
//       for(int i=rows-1; i>0; i--){
//           for(int k=1; k<mode && i-k>=0; k++){
//               if(b[i][j]!=' ' && b[i][j]==b[i-k][j] && i-k<rows){
//                   tracker++;
//                   if(tracker==mode-1 && b[i-(mode-1)][j]==' '){
//                       return j+1;
//                   }
//               }
//           }
//           tracker=1;
//       }
//    }
//   
//   return -1;
//}
//
//int Computer::checkD(Board &board){
//    //Copying private board info with getters
//    char **b = board.getBoard();
//    const int mode=board.getMode();
//    const int rows=board.getRows();
//    //const int cols=board.getCols();
//    int select;
//   
//    for(int i=0; i<rows; i++){ //skipping first row for boundary
//        for(int j=0; j<cols; j++){
//            if(b[i][j]!=' '){
//                
//                // Check diagonal top-left to bottom-right
//                if (i+mode<=rows && j+mode<=cols){
//                        bool win=true;
//                        for (int k=1; k<mode-1; k++) {
//                            if (b[i+k][j+k] != b[i][j]) {
//                                win = false;
//                                break;
//                            }
//                        }
//                        if (win){
//                            if(b[i+mode-1][j+mode-1]==' '){
//                                 select=j+mode-1;
//                                 return select;
//                            }
//                        }
//                    }
//                
//                //Check diagonal top-right to bottom-left
//                if(i+mode<=rows && j-mode+1>=0){
//                    bool win=true;
//                    for(int k=1; k<mode-1; k++){
//                        if(b[i][j]!=b[i+k][j-k]){
//                            win=false;
//                            break;
//                        }
//                    }
//                    if(win){
//                        if(b[i+mode-1][j-mode-1]==' '){
//                              select=j-mode-1;
//                              return select;
//                        }
//                    }
//                }
//                
//            }          
//        }
//    }  
//
//   return -1;
//}
