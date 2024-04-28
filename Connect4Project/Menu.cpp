#include "User.h"
#include "Menu.h"



#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

//Constructor
Menu::Menu(){
  rank = 0;
}

//Destructor
Menu::~Menu() {
  //destroy dynamically allocated variables
}

int Menu::welPage(){
  User user ;
  
  int choice = 0;
  while (choice != 3){
    cout << "\nWELCOME PAGE" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Leaderboard" << endl;
    cout << "3. Sign Out" << endl;
    cout << "Enter your choice: ";
    cin >> choice; 
    
    switch(choice){
      case 1: 
        //start game
        break;
      case 2:
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
