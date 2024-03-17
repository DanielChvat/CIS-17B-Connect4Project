
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


using namespace std;

enum class GameState {
    Player_1, Player_2
};

int main(int argc, char** argv) {

   
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

        
        cout << "Current turn: ";
        (gs == GameState::Player_1) ? cout << "Player 1"<<endl : cout<<"Player 2"<<endl;
       
        int column = crrntPlyr.tkTurn(cols);
       

        if (b.valPlace(column)) {
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
        gs = (gs == GameState::Player_1) ? GameState::Player_2 : GameState::Player_1;
    }



return 0;
}