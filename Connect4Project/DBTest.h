/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   DBTest.h
 * Author: NoahP
 *
 * Created on May 3, 2024, 1:17 AM
 */

#ifndef DBTEST_H
#define DBTEST_H
#include "Database.h"


class DBTest {
public:
    DBTest(char* filename);
    void run();
    ~DBTest();
    

    
private:
    Database* db;
    void signUpUser();
    void loginUser();
    //void showAllUsers(Database& db);
    


};

#endif /* DBTEST_H */

