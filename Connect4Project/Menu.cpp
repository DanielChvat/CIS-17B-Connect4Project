#include "User.h"
#include "Menu.h"
#include <iostream>
#include <ctime>

#include "Game.h"
#include "Menu.h"
#include "Computer.h"
using namespace std; 

/*Features:
Leaderboard Display: Show a leaderboard ranking players based on their scores.
Allows user to sign up or log in
Check password
Check if user exist 
Allow user to start game when user successfully log in 

Functions:
user.logIn();
menu.welPage();
user.signUp();
menu.welPage();
*/

//Constructor
Menu::Menu(){
  rank = 0;
}

//Destructor
Menu::~Menu() {
  //destroy dynamically allocated variables
}


int Menu::welPage(){
  User user;
  
  
  int choice = 0;
  while (choice != 3){
    cout << "\nWELCOME PAGE" << endl;
    cout << "1. Sign Up" << endl;
    cout << "2. Log in" << endl; 
    cout << "3. Leaderboard" << endl;
    cout << "4. Sign Out" << endl;
    cout << "Enter your choice: ";
    cin >> choice; 
    
    switch(choice){
      case 1: 
        //start game
        user.signUp();
        //startGame();
        break;
      case 2:
        user.logIn();
        //display leaderboard
        break;
      case 3:
        //sign out 
        user.logOut();
        break;
    }
  }
  return choice;
}

void Menu::startGame(){
  Game game;
  game.addPlayer(*new Computer(*new Chip('c')));
  game.addPlayer(*new Computer(*new Chip('d')));
  game.run();

  // Win callback test
  game.registerWinCallback([](const Player* player){
    std::cout << "Chip color: " << player->getChip().getColor() << std::endl;
  });
}