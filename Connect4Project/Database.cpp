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
#include <string>
using std::ios;

Datastream::~Datastream() { delete[] this->data; }

void Serializable::WriteToBuf(unsigned char *buffer, const char *data, unsigned long size, unsigned long &cursor){
    for(int i=0; i < size; i++){
        buffer[cursor++] = data[i];
    }
}

void Serializable::ReadFromBuf(const char *buffer, unsigned char *dst, unsigned long size, unsigned long &cursor){
    for(int i=0; i < size; i++){
        dst[i] = buffer[cursor++];
    }
}

Database::Database(char *FileName) {
  this->FileName = FileName;
  this->UserFile.open(FileName, ios::in | ios::out | ios::binary);

  if (!UserFile.is_open()) {
    throw std::string("ERROR: Database could not be loaded!");
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
  delete[] FileName;
  delete[] Records;
  delete FileName;
  delete Records;
}

User *Database::FetchUser(char *UserName) {
  User *temp = nullptr;
  for (int i = 0; i < nRecords; i++) {
    if (Records[i].userName == std::string(UserName))
      temp = &Records[i];
  }
  return temp;
}

bool Database::ValidateUser(char *UserName, char *Password) {
  User *temp = FetchUser(UserName);
  if (!temp && std::string(Password) != temp->password)
    return false;

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

  for (int i = 0; i < nRecords; i++) {
    Datastream recordData = Records[i].Serialize();
    UserFile.write((char *)recordData.data, recordData.size);
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
void EditUser(std::string name, std::string Username, std::string password, User *user){
    if(!user)return;
    
    if(name != "")user->setName(name);
    if(Username != "")user->setUserName(Username);
    if(password != "")user->setPassword(password);
}
