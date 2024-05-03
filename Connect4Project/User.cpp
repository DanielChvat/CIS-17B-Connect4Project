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

#include "User.h"


#include <iostream>
#include <cstring>
#include <ctime>
#include <chrono>
using namespace std;

//Constructor
User::User(){ //set all values to null
  name = '\0';
  userName = '\0';
  password = '\0';
  accAge = 0;
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
  startAccAge(); 
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

//Set the information obtained
void User::setUserName(std::string& userName) {
    this->userName = userName;
}

void User::setName(std::string &name){
    this->name = name;
}

void User::setPassword(std::string &password){
    this->password = password;
}

/*
  make a function that looks, if the user has successfully made their account, then start account age, store the starting date.
*/

void User::startAccAge() {
  // std::chrono::system_clock::time_point registDate;
  // registDate = std::chrono::system_clock::now();
  
  // // std::chrono::system_clock::time_point currTime = std::chrono::system_clock::now();
  // time_t t =std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  // // cout << endl << ctime(&t) << endl;
  // tm *now = std::localtime(&t);
  // cout << std::put_time(now, "%m - %d - %y") << endl;

  // // std::chrono::duration<float> elapsed = currTime - registDate;
  time_t t = time(NULL);
  struct tm date = *localtime(&t);
  cout << "Account enrolled on: " << date.tm_mon + 1 <<" - " << date.tm_mday << date.tm_year +1900 << endl;
  
  
  
  calcAge();
}

void User::calcAge(){ //This calculates the account age based on startAccAge
  // int days = elapsed.count()/(60*60*24);
  // cout << "Account age: " << days << " days." << endl;
  
  //TODO figure out how to calculate the account age in days
}

void User::Load(Datastream *data){
    unsigned long nameSize;
    unsigned long UserNameSize;
    unsigned long passwordSize;
    unsigned long cursor = 0L;
    const char *buffer = (const char *)data->data;

    ReadFromBuf(buffer, (unsigned char *)&nameSize, sizeof(unsigned long), cursor);
    ReadFromBuf(buffer, (unsigned char *)&UserNameSize, sizeof(unsigned long), cursor);
    ReadFromBuf(buffer, (unsigned char *)&passwordSize, sizeof(unsigned long), cursor);

    cout << nameSize << endl;
    cerr << nameSize;
    unsigned char *temp = new unsigned char[nameSize];
    ReadFromBuf(buffer, temp, nameSize, cursor);
    this->name = std::string((const char *)temp);
    delete []temp;


    temp = new unsigned char[UserNameSize];
    ReadFromBuf(buffer, temp, UserNameSize, cursor);
    this->userName = std::string((const char *)temp);
    delete []temp;


    temp = new unsigned char[passwordSize];
    ReadFromBuf(buffer, temp, passwordSize, cursor);
    this->password = std::string((const char *)temp);
    delete []temp;
}

Datastream User::Serialize(){
    unsigned long nameSize = name.size();
    unsigned long UserNameSize = userName.size();
    unsigned long passwordSize = password.size();
    unsigned long recordSize = nameSize + UserNameSize + passwordSize + 3 * sizeof(unsigned long);
    unsigned long cursor = 0L;
    unsigned char *buffer = new unsigned char[recordSize];
    
     WriteToBuf(buffer, (const char *)&nameSize, sizeof(unsigned long), cursor);
     WriteToBuf(buffer, (const char *)&UserNameSize, sizeof(unsigned long), cursor);
     WriteToBuf(buffer, (const char *)&passwordSize, sizeof(unsigned long), cursor);
     WriteToBuf(buffer, name.c_str() , nameSize, cursor);
     WriteToBuf(buffer, userName.c_str(), UserNameSize, cursor);
     WriteToBuf(buffer, password.c_str(), passwordSize, cursor);

     Datastream data(buffer, recordSize);
     return data;
}

