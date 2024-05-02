
/* 
 * File:   GameStates.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on March 20, 2024, 2:49 PM
 */

#include "GameStates.h"

#include "Game.h"

#include "Computer.h"

#include <iostream>

void SetupState::Run() {
    std::cout << "Welcome!\n";

    setupPlayers();
    if (!game_->b_) setupBoard();

    game_->queueState(new TurnState(game_));
}

void SetupState::setupPlayers() {
    game_->p_ = new Player*[game_->getSettings()->numP];

    // char tok;
    Chip cChip('C');
    game_->p_[0] = new Computer(cChip);
    for (int i = 1; i < game_->getSettings()->numP; i++) {
        //    std::cout << "Enter character to represent Player " << i+1 << ": ";
        //    std::cin >> tok;
        // TODO check existing tokens


        // Note: 1 param Player constructor takes in Chip object NOT character
        // Chip c = Chip(tok)
        // or Chip c = Chip()
        // new Player (Chip c )

        // Note: suggest using default Chip constructor because it does input validation 
        Chip chip = Chip();
        game_->p_[i] = new Player(chip);
    }
}

void SetupState::setupBoard() {

    // do {
    //    std::cout << "How wide should the board be? [7-10]: ";
    //    std::cin >> game_->settings_.cols;
    //  } while (game_->getSettings()->cols < 7 || game_->getSettings()->cols > 10);
    //TODO mode selection


    // game_->settings_.rows = game_->settings_.cols-1;
    //  game_->b_ = new Board(
    //          game_->getSettings()->rows,
    //          game_->getSettings()->cols,
    //          game_->getSettings()->mode);


    /*Changes
     * Note: There are getters in board class for rows, cols, mode. 
     * Also I made a setMode function that does what this function does so it might
     * be redundant.
     */

    // Let user choose connect mode and scale board accordingly.
    // Board has a ratio based on connect pattern
    int choice = 0;
    bool valid = false;
    while ( !valid ) {
        cout << "Choose the connect mode ( Connect 4, Connect 5, Connect 6, ETC.): ";
        cin >> choice;
        if (choice >= 4) {

            game_->settings_.mode = choice;

            valid = true;
        } else {
            cerr << "Error: Connect value should be 4 or greater" << endl;
        }
    }

    game_->b_ = new Board( game_->getSettings()->mode+2,
                           game_->getSettings()->mode+3,
                           game_->getSettings()->mode
                         );

}

void TurnState::Enter() {
    
    if(game_->turns_ > 0 )
        game_->b_->displayBoard();
    
}

void TurnState::Run() {
    Player *p = game_->getCurPlayer();
    // Display who's turn it is
   
   
   if(game_->pIdx_==0){
       cout<<"\nComputer's turn " <<endl;
       
   }else{
       cout<<"Player "<<game_->pIdx_+1;
       cout<<": Color "<<game_->getCurPlayer()->getChip().getColor()<<"'s turn."<<endl;
   }
  
    game_->b_->plChip(
            p->tkTurn(game_->b_),
            p->getChip());
    game_->turns_++;

    if (game_->b_->chkWin()) {
        game_->winIdx = game_->pIdx_;
        game_->queueState(new EndState(game_));
    } else {
        game_->pIdx_ = (game_->pIdx_ + 1) % game_->getSettings()->numP; // Increment player index circularly
        game_->queueState(new TurnState(game_));
    }
}

void EndState::Run() {
    // Results Output
    if (game_->winIdx != -1) {
        std::cout << endl;
        game_->b_->displayBoard();
        if(game_->winIdx == 0) 
            cout<<"Computer Wins!";
        else 
            std::cout << "Winner is player " << game_->winIdx + 1 << "!" << std::endl;
        game_->raise_win_event(game_->p_[game_->winIdx]);
        // TODO update win count to player/user account
    } else {
        std::cout << "Y'all suck" << std::endl; // TODO Remove at some point
    }

    // Replay prompt
    char c;
    std::cout << "Rematch? [y/N]: ";
    std::cin >> c;
    if (tolower(c) == 'y') {
        cout << endl << endl;

        // Reset game
        delete game_->b_; // TODO clear the board without deleting it
        game_->b_ = nullptr;
        game_->turns_ = 0;

        game_->queueState(new SetupState(game_));
    } else {
        std::cout << "Thanks for playing!\n";
        game_->end_ = true;
    }
}