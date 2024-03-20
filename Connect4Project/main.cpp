
/* 
 * File:   main.cpp
 * Author: Daniel
 *
 * Created on March 8, 2024, 10:07 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "Game.h"

using namespace std;


int main(int argc, char** argv) {
    int rows = 6;
    int cols = 7;
    int mode = 4;
    
    Game game(rows, cols, mode, 'R', 'B');
    game.run(cols);
return 0;
}