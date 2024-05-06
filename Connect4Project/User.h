#ifndef USER_H
#define USER_H

#include <string>
#include "Database.h"

class User : public Serializable{
  public:
    //Constructor
    User();
    User(std::string, std::string, std::string, int, int, int);

    //Destructor
    ~User();

    //Get information about the user
    std::string getUserName() const;
    std::string getPassword() const;
    std::string getName() const;
    
    //Set the information obtained
    /*NEED SETNAME*/
    void setName(std::string& name);
    void setUserName(std::string& userName);
    void setPassword(std::string& password);
    void startAccAge();    //start account age when user first signed up
    void calcAge();        //calculate age of user's account  

    //Get information about the user
    int getNumPlayed() const;
    int getNumWins() const;
    int getNumLost() const;

    //Set the information obtained
    void setNumPlayed(int /*numPlayed*/);
    void setNumWins(int /*numWins*/);
    void setNumLost(int /*numLost*/);

    //Functions
    void logIn();     //Log in for returning users
    void signUp();    //Sign up for new users
    void logOut();    //Log out
    bool checkPass(const std::string &); /*Check if password for new users meets password requirements 
  - returns true if password is valid, false if not
*/
    Datastream Serialize();
    void Load(Datastream *);

    friend Database;

  private:
    std::string name,
                userName,
                password;
    int accAge, //The date that user made the account
        //month,
        //day,
        //year;
        numWins,
        numLost,
        numPlayed;

};

#endif  