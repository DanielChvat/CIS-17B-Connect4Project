/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Database.cpp
 * Author: 
 * 
 * Created on March 11, 2024, 2:55 PM
 */

#include "Database.h"
#include <fstream>
#include <string>
using std::ios;

Datastream::Datastream(char *data, long size){
	this->data = data;
	this->size = size;
}

Datastream::~Datastream(){
	delete []this->data;
	delete this->size;
}


Database::Database(char *FileName){
	this->FileName = FileName;
	this->UserFile.open(FileName, ios::in | ios::out | ios::binary);

	if(!UserFile){
		throw std::string("ERROR: Database could not be loaded!");
	}

	//Logic For Loading Database all at once
	UserFile.read((char *)&nRecords, sizeof(nRecords));
	Records = new User[nRecords];
                
                //change made here for utilizing Load
	for(int i=0; i < nRecords; i++){
                    Datatsream userDataStream = ReadUserDataStream();
                    Records[i].Load(userDataStream);
            
	}
}

Database::~Database(){
	delete []FileName;
	delete []Records;
	delete FileName;
	delete Records;
}

User *Database::FetchUser(char *UserName){
	User *temp = nullptr;
	for(int i=0; i < nRecords; i++){
		if(Records[i].UserName == UserName)	
			temp = &Records[i];
	}
	return temp;
}

User *Database::Login(char *UserName, char *Password){
	User *temp = FetchUser(UserName);
	if(!temp){
		throw std::string("ERROR: User" + std::string(UserName) + "Was Not Found!");
	}
	
	if(Password != temp->Password){
		throw std::string("ERROR: Invalid Password!");
	}

	return temp;
}



//write user function
void Database::WriteUser(Datastream *data){
    if(data == nullptr) {
        throw std::invalid_argument("Datastream is null.");
    }
    
    if(!UserFile.is_open()) {
        UserFile.open(FileName, ios::out | ios::binary | ios::app);
        if(!UserFile) {
            throw std::runtime_error("File could not be opened for writing.");
        }
    }
    
    //Write the data to the file
    UserFile.write(data->data, data->size);
    if(UserFile.fail()) {
        throw std::runtime_error("Failed to write to file.");
    }
    
    UserFile.close();
}



//function for reading and returning user datastream from file
Datastream Database::ReadUserDatastream(){
    
    //Read the size of the next user record.
    long recordSize = 0;
    UserFile.read(reinterpret_cast<char*>(&recordSize), sizeof(recordSize));
    
    if(UserFile.fail()) {
        throw std::runtime_error("Failed to read record size.");
        
    }
    
    //Allocate buffer for user data.
    char* buffer = new char[recordSize];
    
    //Read the user record data based on the size
    UserFile.read(buffer, recordSize);
    
    //Check if read was successful
    if (UserFile.fail()) {
        delete[] buffer;
        throw std::runtime_error("Failed to read user data.");
    }
    
    return Datastream(buffer, recordSize);
    
}

