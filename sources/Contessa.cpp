#include "Contessa.hpp"

namespace coup{
    /**
     * @brief Contessa source file
     * functions documnatation is found in Contessa header file 
     * 
     */
    Contessa::Contessa(Game &_game, const std::string& name): Player(_game, name){
        this-> title = "Contessa";
        this-> player_name.assign(name);
    }


    void Contessa::block(Player &a){
        this->game->validatesStart(); // Validates that the game started & has atleast 2 players
        if (this->is_not_dead == 0 || a.is_not_dead == 0){ // One of the players are dead
            throw std::runtime_error("Dead players cannot play");
        }

        if(a.title != "Assassin" || a.current_command != "Assassin coup"){ // a is not an assassin OR an assassin that haven't used his assassiante (3 coins coup)
            throw std::runtime_error("Cannot block another class only Assassins / Assassin didn't use steal");
        }

        a.interacted_with-> is_not_dead = 1; // Revived the player & blocked the assassin's coup
    }
}