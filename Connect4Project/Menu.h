#ifndef MENU_H
#define MENU_H

#include "Game.h"
#include <string>

class Menu{
  public:
    //Constructor
    Menu();

    //Destructor
    ~Menu();

    void setup();
    //Menu Welcome Page
    int welPage();

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

  private:
    int rank;

};
#endif  