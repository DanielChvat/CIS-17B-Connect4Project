#ifndef MENU_H
#define MENU_H

#include <string>

class Menu{
  public:
    //Constructor
    Menu();

    //Destructor
    ~Menu();

    //Menu Welcome Page
    int welPage();
  
    //Get information about the user
    int getAccAge() const;
    int getNumPlayed() const;
    int getNumWins() const;
    int getNumLost() const;
    int getLeadBoard() const;

    //Set the information obtained
    /*NEED SETNAME*/
    void getAccAge();
    void setNumPlayed(int /*numPlayed*/);
    void setNumWins(int /*numWins*/);
    void setNumLost(int /*numLost*/);
    void setLeadBoard(int /*leadBoard*/);

    //Functions
    void logOut();    //Log out
    void checkAcc();  //Check if account exists in binary file 
    bool checkPass(const std::string &); /*Check if password for new users meets password requirements 
  - returns true if password is valid, false if not
*/

  private:
    int accAge,
        numWins,
        numLost,
        numPlayed,
        rank;

};
#endif  