#include "User.h"
#include "Menu.h"
#include <iostream>
#include <ctime>

#include "Game.h"
#include "Menu.h"

using namespace std;

int main(int argc, char** argv) {

    Game game;
    game.run();

    // Win callback test
    game.registerWinCallback([](const Player* player){
      std::cout << "Chip color: " << player->getChip().getColor() << std::endl;
    });
  
//   User user;
//   Menu menu; 
//   //user.signUp();
  
//   int menu1 = 0;
//   while (menu1 != 3){
//     cout << "Menu" << endl;
//     cout << "1. LOG IN" << endl;
//     cout << "2. SIGN UP" << endl;
//     cout << "3. EXIT" << endl;
//     cout << "Enter your choice: ";
//     cin >> menu1;

//     switch(menu1) {
//       case 1: 
//         user.logIn();
//         menu.welPage();
//         break;
//       case 2: 
//         user.signUp();
//         menu.welPage();
//         break;
//   }

    return 0;
}