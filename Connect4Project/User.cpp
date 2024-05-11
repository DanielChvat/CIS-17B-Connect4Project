#include "User.h"
#include "Game.h"
#include "Computer.h"

#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <chrono>
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
}

User::User(std::string name, std::string userName, std::string password, int nWins, int nLosses, int nPlayed){
    this->name = name;
    this->userName = userName;
    this->password = password;
    this->numLost = nLosses;
    this->numPlayed = nPlayed;
    this->numWins = nWins;
}

//Destructor
User::~User(){
  //destroy dynamically allocated variables
}

//Functions
void User::logIn(){
  Database data("user.dat");
  cout << "Enter your username: ";
  cin >> userName;

  cout << "Enter your password: ";
  cin >> password;

  if(data.ValidateUser(userName, password)){
    cout << "Login successful!\n";
    Game game;
    User *u = data.FetchUser(userName);
    
    Player *p = new Player(*new Chip('p'));
    game.addPlayer(*new Computer(*new Chip('c')));
    game.addPlayer(*p);
    game.run();
    
    
    if(p->getWon())u->setNumWins(u->getNumWins() + 1);
    else u->setNumLost(u->getNumLost() + 1);
    u->setNumPlayed();
    
    
  } else{
      cout << "Login failed\n";
  }
 
  // BinFile binary;
  // binary.logIn("Data.bin", *data);
}

void User::signUp(){
  User newUser;
 
  cout << "Enter your name: ";
  cin >> newUser.name;

  cout << "Enter your username: ";
  cin >> newUser.userName;

  cout << "Enter your password: ";
  cin >> newUser.password;
  bool status = checkPass(newUser.password);
  status = true;
  
  while (!status) {
    cout << "\nPassword does not fulfill requirements."<< endl;
    cout << "Password must be 8-16 characters long and contain at least one uppercase letter, lowercase letter, and a digit." << endl;
    cout << "\nRe-enter password: ";
    cin >> newUser.password;
    status = checkPass(newUser.password);
  }
  Database data("user.dat");
  data.addUser(newUser);
//  data.EditUser(newUser->name, newUser->userName, newUser->password, newUser);
  data.WriteRecords();
  //std::string name, std::string Username, std::string password, User *user
  
  cout << "Sign up successful!\n" << endl;
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
      //if password contains a digit, then requirement is satisfied
    }
    if (isupper(letter)) {
      statusUp = true;
      //if password contains uppercase, then requirement is satisfied
    }
    if (islower(letter)) {
      statusLow = true;
      //if password contains lowercase, then requirement is satisfied
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


string User::getName() const {
  return name;
}

string User::getPassword() const {
  return password;
}

//Set the information obtained
void User::setUserName(std::string& userName) {
    this->userName = userName;
}

void User::setName(std::string& name) {
    this->name = name;
}

void User::setPassword(std::string& password) {
    this->password = password;
}

/*
  make a function that looks, if the user has successfully made their account, then start account age, store the starting date.
*/

void User::startAccAge() {
  std::time_t pst =std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) - (8 * 60 * 60);
  
  struct tm *pstDate = std::localtime(&pst);
  // month = pstDate->tm_year + 1900;
  // day = pstSate

  //UTC is 8 hours ahead of PST
  cout << "Account enrolled on: " << std::put_time(pstDate, "%m - %d - %y") << std::endl;
  
  
  calcAge();
}

void User::calcAge(){ //This calculates the account age based on startAccAge
  // int days = elapsed.count()/(60*60*24);
  // cout << "Account age: " << days << " days." << endl;


  
  std::time_t pst =std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) - (8 * 60 * 60);

  //struct tm *pstDate = std::localtime(&pst);
  
  std::time_t curTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::time_t timeDiff = curTime - pst;
  //float time = difftime(curTime, pstDate);

  int days = static_cast<int>(timeDiff / (60 * 60 * 24));
  std::cout << "Account age: " << days << endl << endl;
}

void User::Load(Datastream *data){
    unsigned long nameSize;
    unsigned long UserNameSize;
    unsigned long passwordSize;
    unsigned long cursor = 0L;
    const char *buffer = (const char *)data->data;

    ReadFromBuf(buffer, (char *)&nameSize, sizeof(unsigned long), cursor);
    ReadFromBuf(buffer, (char *)&UserNameSize, sizeof(unsigned long), cursor);
    ReadFromBuf(buffer, (char *)&passwordSize, sizeof(unsigned long), cursor);

    char *temp = new char[nameSize + 1];
    ReadFromBuf(buffer, temp, nameSize, cursor);
    temp[nameSize] = '\0';
    this->name = std::string((const char *)temp);
    delete []temp;


    temp = new char[UserNameSize + 1];
    ReadFromBuf(buffer, temp, UserNameSize, cursor);
    temp[UserNameSize] = '\0';
    this->userName = std::string((const char *)temp);
    delete []temp;


    temp = new char[passwordSize + 1];
    ReadFromBuf(buffer, temp, passwordSize, cursor);
    temp[passwordSize] = '\0';
    this->password = std::string((const char *)temp);
    delete []temp;
    
    
    ReadFromBuf(buffer, (char *)&this->numWins, sizeof(int), cursor);
    ReadFromBuf(buffer, (char *)&this->numLost, sizeof(int), cursor);
    ReadFromBuf(buffer, (char *)&this->numPlayed, sizeof(int), cursor);         
}

Datastream User::Serialize(){
    unsigned long nameSize = name.size();
    unsigned long UserNameSize = userName.size();
    unsigned long passwordSize = password.size();
    unsigned long cursor = 0L;
    unsigned long recordSize = nameSize + UserNameSize + passwordSize + 3 * sizeof(unsigned long) + 3 * sizeof(int);
    char *buffer = new char[recordSize + sizeof(unsigned long)];
    
    WriteToBuf(buffer, (const char *)&recordSize, sizeof(unsigned long), cursor);
    WriteToBuf(buffer, (const char *)&nameSize, sizeof(unsigned long), cursor);
    WriteToBuf(buffer, (const char *)&UserNameSize, sizeof(unsigned long), cursor);
    WriteToBuf(buffer, (const char *)&passwordSize, sizeof(unsigned long), cursor);
    WriteToBuf(buffer, name.c_str() , nameSize, cursor);
    WriteToBuf(buffer, userName.c_str(), UserNameSize, cursor);
    WriteToBuf(buffer, password.c_str(), passwordSize, cursor);
    WriteToBuf(buffer, (const char *)&this->numWins, sizeof(int), cursor);
    WriteToBuf(buffer, (const char *)&this->numLost, sizeof(int), cursor);
    WriteToBuf(buffer, (const char *)&this->numPlayed, sizeof(int), cursor);

     Datastream data(buffer, recordSize + sizeof(unsigned long));
     return data;
}

//Getters
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

//Setters
void User::setNumPlayed() {
    this->numPlayed = this->numLost + this->numWins;
}

void User::setNumWins(int numWins) {
    this->numWins = numWins;
}

void User::setNumLost(int numLost) {
    this->numLost = numLost;
}