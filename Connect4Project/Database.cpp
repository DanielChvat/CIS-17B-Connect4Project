/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt
 * to change this license Click
 * nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this
 * template
 */

/*
 * File:   Database.cpp
 * Author:
 *
 * Created on March 11, 2024, 2:55 PM
 */

#include "Database.h"
#include "User.h"
#include <fstream>
#include <iostream>
#include <string>
using std::ios;

Datastream::~Datastream() { delete[] this->data; }

void Serializable::WriteToBuf(char *buffer, const char *data, unsigned long size, unsigned long &cursor){
    for(int i=0; i < size; i++){
        buffer[cursor++] = data[i];
    }
}

void Serializable::ReadFromBuf(const char *buffer, char *dst, unsigned long size, unsigned long &cursor){
    for(int i=0; i < size; i++){
        dst[i] = buffer[cursor++];
    }
}

Database::Database(std::string FileName) {
  this->FileName = FileName;
  this->UserFile.open(FileName, ios::in | ios::binary);
  
  if (!UserFile.is_open()) {
      this->UserFile.open(FileName, ios::out | ios::binary | ios::trunc);
      
      if (!UserFile.is_open()){
          //throw std::string("ERROR: Database could not be loaded!");
      }
    
      
  }
  
  
   
   if (!UserFile.is_open()) {
        //throw std::runtime_error("ERROR: Database could not be re-opened for read-write operations.");
    }
   
  // Logic For Loading Database all at once
  UserFile.read((char *)&nRecords, sizeof(nRecords));
  Records = new User[nRecords];
  
  // change made here for utilizing Load
  for (int i = 0; i < nRecords; i++) {
    Datastream userDataStream = ReadUserDatastream();
    Records[i].Load(&userDataStream);
  }
  UserFile.close();
}

Database::~Database() {
    this->WriteRecords();
    delete[] Records;
}

User *Database::FetchUser(std::string UserName) {
  for (int i = 0; i < nRecords; i++) {
    if (Records[i].userName == UserName)
        return &Records[i];
  }
  return nullptr;
}

User *Database::FetchUser(int n){
    return &this->Records[n];
}

bool Database::ValidateUser(std::string UserName, std::string Password) {
  User *temp = FetchUser(UserName);
  
  if (!temp || Password != temp->password) return false;

  return true;
}

// write all users in the database function
void Database::WriteRecords() {
  if (!UserFile.is_open()) {
    UserFile.open(FileName, ios::out | ios::binary | ios::trunc);
    if (!UserFile) {
      throw std::runtime_error("File could not be opened for writing.");
    }
  }
  
  UserFile.write((char *)&nRecords, sizeof(nRecords));

  for (int i = 0; i < nRecords; i++) {
    Datastream recordData = Records[i].Serialize();
    UserFile.write(recordData.data, recordData.size);
  }

  UserFile.close();
}

// function for reading and returning user datastream from file
Datastream Database::ReadUserDatastream() {

  // Read the size of the next user record.
  long recordSize = 0;
  UserFile.read(reinterpret_cast<char *>(&recordSize), sizeof(recordSize));

  if (UserFile.fail()) {
    throw std::runtime_error("Failed to read record size.");
  }

  // Allocate buffer for user data.
  char *buffer = new char[recordSize];

  // Read the user record data based on the size
  UserFile.read(buffer, recordSize);

  // Check if read was successful
  if (UserFile.fail()) {
    delete[] buffer;
    throw std::runtime_error("Failed to read user data.");
  }

  return Datastream(buffer, recordSize);
}

// Function for Admin to Edit User Data
void Database::EditUser(std::string name, std::string Username, std::string password, User *user){
    if(!user)return;
    
    if(name != "") user->setName(name);
    if(Username != "") user->setUserName(Username);
    if(password != "") user->setPassword(password);
}

void Database::addUser(User newUser){
    User *temp = new User[this->nRecords + 1];
    
    for(int i=0; i < this->nRecords; i++){
        temp[i] = Records[i];
    }
    temp[nRecords] = newUser;
    
    delete []Records;
    this->Records = temp;
    nRecords++;
}

void Database::deleteUser(int n){
    int offset = 0;
    User *temp = new User[this->nRecords - 1];
    for(int i=0; i < this->nRecords; i++){
        if(i == n) {
            offset = 1;
            continue;
        }
        
        temp[i - offset] = this->Records[i];
    }
    delete []this->Records;
    this->Records = temp;
    this->nRecords--;
}