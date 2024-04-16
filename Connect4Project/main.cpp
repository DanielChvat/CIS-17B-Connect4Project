
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
    Game game;

    // Win callback test
    game.registerWinCallback([](const Player* player){
      std::cout << "Chip color: " << player->getChip().getColor() << std::endl;
    });

    game.run();

    return 0;
}