#ifndef MENU_H
#define MENU_H

#include "Game.h"
#include "Database.h"
#include <string>

class Menu{
  public:
    //Constructor
    Menu();

    //Destructor
    ~Menu();

    void setup();
    //Menu Welcome Page
    void welPage();

    //get leaderboard stats
    int getLeadBoard() const;

    //set leaderboard stats
    void setLeadBoard(int /*leadBoard*/);

    //Functions
    void logOut();    //Log out
    void checkAcc();  //Check if account exists in binary file 
    bool checkPass(const std::string &); /*Check if password for new users meets password requirements 
  - returns true if password is valid, false if not
*/
    
    static void adminMenu(Database &);
    static void displayUsers(Database &);
    static void EditUser(Database &);
  private:
    int rank;
//    Database *db;

};
#endif  