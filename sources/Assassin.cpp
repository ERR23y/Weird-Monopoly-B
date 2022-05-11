#include "Assassin.hpp"

namespace coup{
    /**
    * @brief Assassin source file
    * functions documnatation is found in Assassin header file 
    * 
    */

    Assassin::Assassin(Game &_game, const std::string& name): Player(_game, name){

                this-> title = "Assassin";
                this-> player_name.assign(name);
    }

    void Assassin::coup(Player &a){
        this->game->validatesStart(); // Validates that the game started & has atleast 2 players
        if (this->is_not_dead == 0 || a.is_not_dead == 0){ // One of the players are dead
            throw std::runtime_error("Dead players cannot play");
        }
            
        if(this->game->current_turn() != this->player_name){ // Not turn of current player
            throw std::runtime_error("Not turn of " + this->player_name);
        }
        
        if(this->coins() < ASSASSIN_COUP){
            throw std::runtime_error("Cannot coup player " + a.player_name + " due to lack of coins");
        }
        
        /**
         * @brief Thanks to Almog David in the c++ group (instructions weren't clear enough so had to ask)
         * 
         */
        if(this->coins() >= COUP){ // Assassin has more than 7 coins so normal coup 
            this->coinsAmount -= COUP;
        }else{ // Assassins activate its "special coup" which requires 3 coins
            this->coinsAmount-=ASSASSIN_COUP;
            this-> current_command = "Assassin coup"; // Special coup
        }
        
        a.is_not_dead = 0; // Got assassinated
        this-> interacted_with = &a;  // Points on assassinated player in case Contessa want to revive
        this->game->notDead() == 1 ? this->game->endGame() : this->nextPlayer(); // Amount of remaining alive players is 1? finish game, else next turn
    }
}     
