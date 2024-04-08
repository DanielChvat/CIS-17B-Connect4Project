/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Database.h
 * Author: 
 *
 * Created on March 11, 2024, 2:55 PM
 */

#ifndef DATABASE_H
#define DATABASE_H

#include "User.h"
#include <fstream>

class Datastream {
public:
	Datastream(char *, long);
	~Datastream();
private:
	char *data;
	long size;
};
 
class Serializable {
public:
	Serializable();
private:
	virtual Datastream Serialize();
	virtual Datastream Load();
};

class Database {
public:
	Database(char *);	
	~Database();
	User *Login(char *, char *);	
	void WriteUser(Datastream *);
                Datastream ReadUserDatastream();
private:
	std::fstream UserFile;
	char *FileName;
	User *Records;
	long nRecords = 0;
	User *FetchUser(char *);
};

#endif /* DATABASE_H */

