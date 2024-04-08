/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   User.h
 * Author: Aurelia, Aurelisa, Brittany
 *
 * Created on March 8, 2024, 11:29 AM
 */

#ifndef USER_H
#define USER_H

#include <string>

class User{
  public:
    //Constructor
    User();

    //Destructor
    ~User();

    //Get information about the user
    std::string getUserName() const;
    
    //Set the information obtained
    /*NEED SETNAME*/
    void setUserName(/*std::string& userName*/);
    void startAccAge();    //start account age when user first signed up
    void calcAge();        //calculate age of user's account  
    
    //Functions
    void logIn();     //Log in for returning users
    void signUp();    //Sign up for new users
    void logOut();    //Log out
    bool checkPass(const std::string &); /*Check if password for new users meets password requirements 
  - returns true if password is valid, false if not
*/
    

  private:
    std::string name,
                userName,
                password;
    int accAge; //The date that user made the account
        //month,
        //day,
        //year;

};

#endif   /* USER_H */
