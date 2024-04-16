#include "User.h"
#include "Menu.h"
#include <iostream>
using namespace std;

int main() {
  User user;
  Menu menu; 
  //user.signUp();
  
  int menu1 = 0;
  while (menu1 != 3){
    cout << "Menu" << endl;
    cout << "1. LOG IN" << endl;
    cout << "2. SIGN UP" << endl;
    cout << "3. EXIT" << endl;
    cout << "Enter your choice: ";
    cin >> menu1;

    switch(menu1) {
      case 1: 
        user.logIn();
        menu.welPage();
        break;
      case 2: 
        user.signUp();
        menu.welPage();
        break;
  }
  return 0;
  }
}