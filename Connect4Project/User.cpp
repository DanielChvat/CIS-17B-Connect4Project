/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   User.cpp
 * Author: Aurelia, Aurelisa, Brittany
 * 
 * Created on March 8, 2024, 11:29 AM
 */

// System Libraries
#include "User.h"
#include "GameStates.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

//Constructor
User::User(){ //set all values to null
  name = '\0';
  userName = '\0';
  password = '\0';
  accAge = 0;
  numWins = 0;
  numLost = 0;
  numPlayed = 0;
  rank = 0;
}

//Destructor
User::~User(){
  //destroy dynamically allocated variables
  
}

//Functions
void User::logIn(){
  cout << "Enter your username: ";
  cin >> userName;

  cout << "Enter your password: ";
  cin >> password;

  // BinFile binary;
  // binary.logIn("Data.bin", *data);
}

void User::signUp(){
  cout << "Enter your name: ";
  cin >> name;

  cout << "Enter your username: ";
  cin >> userName;

  cout << "Enter your password: ";
  cin >> password;

  bool status = checkPass(password);
  
  while (!status) {
    cout << "\nPassword does not fulfill requirements."<< endl;
    cout << "Password must be 8-16 characters long and contain at least one uppercase letter, lowercase letter, and a digit." << endl;
    cout << "\nRe-enter password: ";
    cin >> password;
    status = checkPass(password);
  }
  cout << "Sign up successful!" << endl;
  
}

void User::logOut(){
  cout << "Successfully logged out." << endl;
}

bool User::checkPass(const string &password){
  //should we define these constants in the .h file?
  int MIN_LENGTH = 8;
  int MAX_LENGTH = 16;
  bool statusLen = false, //True if satisfies length requirement
      statusUp = false, //True if there is uppercase letter
      statusLow = false, //True if there is lowercase letter
      statusDig = false; //True if there is a digit
  

  //check password length
  if (password.length() >= MIN_LENGTH && password.length() <= MAX_LENGTH) {
    statusLen = true;
  } else{
    statusLen = false;
  }

  //check each letter in password
  for (char letter : password) {
    if (isdigit(letter)) {
      statusDig = true;
      //if password contains a digit, then requirement is satisified
    }
    if (isupper(letter)) {
      statusUp = true;
      //if password contains uppercase, then requirement is satisified
    }
    if (islower(letter)) {
      statusLow = true;
      //if password contains lowercase, then requirement is satisified
    }
  }
  return (statusLen&&statusDig&&statusUp&&statusLow);
  /*check if password meets password requirements:
  - MIN_LENGTH = 8
  - MAX_LENGTH = 16
  - 8 <= length <= 16
  - length >= 8 length <=16
  - uppercase letters
  - lowercase letters
  - at least 1 number
  - no need special character
*/
  
}

// Get information about the user
string User::getUserName() const {
  return userName;
}

int User::getNumPlayed() const {
  //Read numPlayed from binary file
  return numPlayed;
}
int User::getNumWins() const {
  //Read numWins from binary file
  return numWins;
}
int User::getNumLost() const {
  //Read numLost from binary file
  return numLost;
}


//Set the information obtained
void User::setUserName(/*std::string& userName*/) {
  cin >> userName;
}
void User::setNumPlayed(int numPlayed) {
  numPlayed = 0;
  numPlayed = numWins + numLost;
}
void User::setNumWins(int numWins) {
  // if(wIndx))
  //     numWin++;

}

void User::setNumLost(int numLost) {
  /*
      if(player !win)
        numLost++;
  */
}
