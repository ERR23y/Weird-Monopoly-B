#include "Captain.hpp"


namespace coup{

    Captain::Captain(Game &_game, const std::string& name): Player(_game, name){
            this-> title = "Captain";
            this-> player_name.assign(name);
    }
    
    void Captain::block(Player &a){ 
        this->game->validatesStart(); // Validates that the game started & has atleast 2 players
        if (this->is_not_dead == 0 || a.is_not_dead == 0){ // One of the players are dead
            throw std::runtime_error("Dead players cannot play");
        }

        if(a.title != "Captain" || a.current_command != "Captain steal"){ // a is not a captain OR a captain that haven't used captain's steal
            throw std::runtime_error("Cannot block another class only captains / Cpatain didn't use steal");
        }

        // Blocked the other captain so returns the coins (2) to the player whose got stolen
        a.coinsAmount -= 2;
        a.interacted_with->coinsAmount += 2;
        
    }

    void Captain::steal(Player &a){
        this->game->validatesStart(); // Validates that the game started & has atleast 2 players
        if (this->is_not_dead == 0 || a.is_not_dead == 0){ // One of the players are dead
            throw std::runtime_error("Dead players cannot play");
        }

        if(this->game->current_turn() != this->player_name){
            throw std::runtime_error("Not turn of " + this->player_name);
        }

        this-> interacted_with = &a; // Captain stole from player a therefore it points on player a
        this-> current_command = "Captain steal"; // Current command of captain

        int posession = a.coins() >= 2 ? 2 : a.coins() == 1 ? 1 : 0 ; // Trenary if-else, what happens if a holds more than 2 coins, 1 coin or zero coins.
        // Takes from player and gives the captain
        a.coinsAmount -= posession;
        this-> coinsAmount += posession;

        this->nextPlayer(); // Next turn
    }
}
