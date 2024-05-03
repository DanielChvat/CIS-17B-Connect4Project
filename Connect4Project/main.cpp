
/* 
 * File:   main.cpp
 * Author: Daniel
 *
 * Created on March 8, 2024, 10:07 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>


#include "DBTest.h"

using namespace std;


int main(int argc, char** argv) {
    cout << "Yuh" << endl;
    const char* str = "User.bin";
    char* filename = const_cast<char*>(str);
    cout << filename << endl;
    DBTest tester(filename);
    tester.run();
    
//    Game game;
//    game.run();

    
    
    return 0;
}