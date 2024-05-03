/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   DBTest.cpp
 * Author: NoahP
 * 
 * Created on May 3, 2024, 1:17 AM
 */

#include<iostream>


#include "DBTest.h"
#include "User.h"

DBTest::DBTest(char* filename) {
    db = new Database(filename);
}

DBTest::~DBTest() {
    delete db;
}

void DBTest::run() {
    int choice = -1;
    
    while (choice != 0) {
        std::cout << "1: Add User" << std::endl;
        std::cout << "2: Log In" << std::endl;
        std::cout << "3. Show All Users" << std::endl;
        std::cout << "0: Exit" << std::endl;
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                signUpUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                //showAllUsers();
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                return;
                
            default:
                std::cout << "Invalid option, try again." << std::endl;
        }
    }
}

void DBTest::signUpUser(){
    User newUser;
    newUser.signUp();
    
    int numUsers = db->getNumberOfRecords();
    User* users = db->getRecords();
    
    for (int i = 0; i < numUsers; i++) {
        if (users[i].getUserName() == newUser.getUserName()) {
          std::cout << "Error: User already exists." << std::endl;
          return;
        }
    }
    
    
    User* updatedUsers = new User[numUsers + 1];
    for(int i = 0; i < numUsers; i++) {
        updatedUsers[i] = users[i];
    }
    updatedUsers[numUsers] = newUser;
    
    
    db->setRecords(updatedUsers, numUsers + 1);
    db->WriteRecords();
    
    std::cout << "Signup complete; database updated" << std::endl;
    
}

void DBTest::loginUser() { 

    std::string username, password;
    std::cout << "Enter usernames: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    if (db->ValidateUser(const_cast<char*>(username.c_str()), const_cast<char*>(password.c_str()))) {
            std::cout << "Login successful.\n";
    } 
    else {
        std::cout << "Login failed.\n";
    }

}


//void showAllUsers ()) {
//    std::cout << "Registered Users:" << std::endl;
//    
//    auto users = db.getAllUsers();
//    for (const User& user : users) {
//        std::cout << "Name: " << user.getName() << " , Username: " << user.getUserName() << std::endl;
//    }
//}