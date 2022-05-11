#include "Duke.hpp"

namespace coup{
    /**
     * @brief Duke source file (to be implemented)
     * functions documnatation is found in Duke header file 
     * 
     */
    Duke::Duke(Game &_game, const std::string &name) : Player(_game, name){
        this-> title = "Duke";
        this-> player_name.assign(name);
    }
    
    void Duke::block(Player &a){ 
        this->game->validatesStart(); // Validates that the game started & has atleast 2 players
        if (this->is_not_dead == 0 || a.is_not_dead == 0){ // One of the players are dead
            throw std::runtime_error("Dead players cannot play");
        }
        if(a.current_command != "Foreign_aid"){
            throw std::runtime_error("Current player didn't use foreign aid");
        }

        a.coinsAmount -= 2;
    }

    void Duke::tax(){
        this->game->validatesStart(); // Validates that the game started & has atleast 2 players
        if (this->is_not_dead == 0){  // Current player is dead
            throw std::runtime_error("Dead players cannot play");
        }
        if(this->game->current_turn() != this->player_name){ // Not turn of current player
            throw std::runtime_error("Not turn of " + this->player_name);
        }

        this->coinsAmount += 3; // Takes 3 coins
        this->nextPlayer();
    }

}