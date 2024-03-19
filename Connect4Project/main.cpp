/* 
 * File:   main.cpp
 * Author: Daniel
 *
 * Created on March 8, 2024, 10:07 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "Board.h"
#include "Player.h"
#include "Computer.h"

using namespace std;

enum class GameState {
    Player_1, Player_2
};

int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    int rows = 9;
    int cols = 10;
    int mode = 7;

    Board b = Board(rows, cols, mode);

    Chip red = Chip('R');
    Chip blue = Chip('B');

    Player p1 = Player(red);
    Player p2 = Player(blue);

    GameState gs = GameState::Player_1;

    while (true) {
        b.displayBoard();

        Player& crrntPlyr = (gs == GameState::Player_1) ? p1 : p2;
        Computer computer;
        
        cout << "Current turn: ";
        (gs == GameState::Player_1) ? cout << "Player 1"<<endl : cout<<"Player 2"<<endl;
       
        int column; //Column for chip placement
        
        //If Player1 turn, prompt user for input
        if(gs == GameState::Player_1){
            column=crrntPlyr.tkTurn(cols);
            while(!b.tempVal(column)){
                cout << "Invalid column selection. Please enter a valid column number"<<" (1-"<<cols<<"): ";
                cin >> column;
            }
        }
        
        //Computer turn
        else{
            do{
               column=computer.rTurn(cols);
            }while(b.tempVal(column)==false); 
        }
        
        //If valid chip placement, place chip & check for winner
        if(b.tempVal(column)==true){
            b.plChip(column , crrntPlyr.getChip() );
            
            char winner = b.chkWin();

            if (winner != '\0') {
                b.displayBoard();
                if (gs == GameState::Player_1) {
                    cout << "Player 1 wins" << endl;
                } else {
                    cout << "Player 2 wins" << endl;
                }
                break;
            }
        }
        
        //If GameState is Player1, alternate GameState to Player2
        gs = (gs == GameState::Player_1) ? GameState::Player_2 : GameState::Player_1;
    }



return 0;
}