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

/* #include "User.h" */
#include <fstream>

class User;


class Datastream {
public:
    Datastream(char *data, long size) : data(data), size(size){}
    Datastream(){}
    ~Datastream();
    char *data;
    long size;
};
 
class Serializable {
public:
    void WriteToBuf(char *dst, const char *src, unsigned long size, unsigned long &cursor);
    void ReadFromBuf(const char *src, char *dst, unsigned long size, unsigned long &cursor);
private:
    virtual Datastream Serialize() = 0;
    virtual void Load(Datastream *) = 0;
};

class Database {
public:
    Database(char *);	
    ~Database();
    bool ValidateUser(char *, char *);	
    void EditUser(std::string name = "", std::string Username = "", std::string password = "", User *user = nullptr);
    void WriteRecords();
    Datastream ReadUserDatastream();
private:
	std::fstream UserFile;
	char *FileName;
	User *Records;
	long nRecords = 0;
	User *FetchUser(char *);
};

#endif /* DATABASE_H */

