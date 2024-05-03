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
    Database(std::string);	
    ~Database();
    bool ValidateUser(std::string, std::string);
    void addUser(User);
    void EditUser(std::string name = "", std::string Username = "", std::string password = "", User *user = nullptr);
    void WriteRecords();
    User *FetchUser(std::string);
    long UserCount() {return nRecords;}
private:
    std::fstream UserFile;
    std::string FileName;
    User *Records;
    long nRecords = 0;
    
    Datastream ReadUserDatastream();
};

#endif /* DATABASE_H */

