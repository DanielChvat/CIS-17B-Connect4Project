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
	delete this->data;
}

Database::Database(char *FileName){
	this->FileName = FileName;
	this->UserFile.open(FileName, ios::in | ios::out | ios::binary);

	while(!UserFile){
		throw std::string("ERROR: Database could not be loaded!");
	}

	//Logic For Loading Database all at once
	UserFile.read((char *)&nRecords, sizeof(nRecords));
	Records = new User[nRecords];

	for(int i=0; i < nRecords; i++){
		/* Records[i].UserName = UserFile.read(); */
		/* Records[i].Password = UserFile.read(); */
		/* Records[i].Wins = UserFile.read(); */
		/* Records[i].Losses = UserFile.read(); */
		/* Records[i].Icon = UserFile.read(); */
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

void Database::WriteUser(Datastream *data){
	
}
