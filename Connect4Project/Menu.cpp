#include "User.h"
#include <iostream>
#include <ctime>

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


void Menu::welPage(){
  User user;
  
  
  int choice = 0;
  while (choice != 3){
    cout << "WELCOME PAGE" << endl;
    cout << "1. Sign Up" << endl;
    cout << "2. Log in (admin username: \"admin\", admin password: \"password\")" << endl; 
//    cout << "3. Leaderboard" << endl;
    cout << "3. Sign Out" << endl;
    cout << "Enter your choice: ";
    cin >> choice; 
    cout << endl;
    
    switch(choice){
      case 1: 
        //start game
        user.signUp();
        goto case2;
        
        break;
      case 2:
        case2:
        user.logIn();
          
        break;
      case 3:
        //sign out 
        user.logOut();
        break;
    }
  }
}

void Menu::adminMenu(){
    char choice;
    do{
        cout << "ADMIN VIEW" << endl;
        cout << "1. View Users" << endl;
        cout << "2. Edit User" << endl;
        cout << "3. Exit" << endl;
        
        cin >> choice;
        
        switch(choice){
            case '1': Menu::displayUsers();break;
            case '2': break;
        }
    }while(choice != '3');
    
}

void Menu::displayUsers(){
    Database data("user.dat");
    for(int i = 0; i < data.UserCount(); i++){
        User *u = data.FetchUser(i);
        cout << "User " << i + 1 << endl;
        cout << "Username    : " << u->getUserName() << endl;
        cout << "Password    : " << u->getPassword() << endl;
        cout << "Admin       : " << (u->isAdmin()?"Yes":"No") << endl;
        cout << "Wins        : " << u->getNumWins() << endl;
        cout << "Losses      : " << u->getNumLost() << endl;
        cout << "Games Played: " << u->getNumPlayed() << endl << endl;
    }
}