#include "User.h"
#include "Menu.h"
#include "GameStates.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

//Constructor
Menu::Menu(){
  numWins = 0;
  numLost = 0;
  numPlayed = 0;
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

//Getters
int Menu::getNumPlayed() const {
  //Read numPlayed from binary file
  return numPlayed;
}

int Menu::getNumWins() const {
  //Read numWins from binary file
  return numWins;
}

int Menu::getNumLost() const {
  //Read numLost from binary file
  return numLost;
}

//Setters
void Menu::setNumPlayed(int numPlayed) {
  numPlayed = 0;
  numPlayed = numWins + numLost;
}

void Menu::setNumWins(int numWins) {
  // if(wIndx))
  //     numWin++;
}

void Menu::setNumLost(int numLost) {
  /*
      if(player !win)
        numLost++;
  */
}
