#include "Ambassador.hpp"

namespace coup{

    /**
    * @brief Aambassador source file (to be implemented)
    * functions documnatation is found in Ambassador header file 
    * 
    */
    Ambassador::Ambassador(Game &_game, const std::string& _name): Player(_game, _name){

            this-> title = "Ambassador";
            this-> player_name.assign(_name);
    }

    void Ambassador::transfer(Player &a, Player &b){
        this->game->validatesStart(); // Validates that the game started & has atleast 2 players
        if(this-> is_not_dead == 0 || a.is_not_dead == 0 || b.is_not_dead == 0){ // Verify that one of the players aren't dead
            throw std::runtime_error("Dead players cannot play");
        }
        
        if(this-> game -> current_turn() != this-> player_name){ // Not turn of current player
            throw std::runtime_error("Not turn of " + this->player_name);
        }

        if (a.coins() <= 0){ // a has 0 coins
            throw std::runtime_error("Cannot transfer from " + a.player_name + " due to lack of coins");
        }

        this-> current_command = "Captain steal";
        // Takes from player 1 transfer to player b
        a.coinsAmount--;
        b.coinsAmount++;
        this->nextPlayer(); // Next turn
    }

    void Ambassador::block(Player &jack_sparrow){
        this->game->validatesStart(); // Validates that the game started & has atleast 2 players
        if (this->is_not_dead == 0 || jack_sparrow.is_not_dead == 0){ // Verify that one of the players aren't dead
            throw std::runtime_error("Dead players cannot play");
        }

        if(jack_sparrow.title != "Captain" || jack_sparrow.current_command != "Captain steal"){ // Jack sparrow is not a captain/ Jack sparrow didn't chose to steal
            throw std::runtime_error("Ambassador can only block captains/No captain steal anything");
        }

        // Takes coins from Jack and returns it to the player he stole coins from
        jack_sparrow.coinsAmount -= 2;
        jack_sparrow.interacted_with-> coinsAmount += 2;
    }
}
