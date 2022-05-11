#include "Player.hpp"

namespace coup{

    Player::Player(Game &game, const std::string& player_name){
        this->game = &game; // If not put it here then get weird error (That's the only way to solve it)
        if(this->game->list_of_players.size() == MAX_PLAYERS){ // If 6 players has already join the game - cannot add another
            throw std::runtime_error("Too many players, cannot join");
        }
        
        if(this->game->goinOn()){ // Game has started
            throw std::runtime_error("Game already has begun, cannot add more players"); 
        }

        this->game->list_of_players.push_back(this); // Adds to the game a player
        this->player_name.assign(player_name);       // Assign the player's name
        this->coinsAmount = 0;                       // Player starts with 0 coins
        this->is_not_dead = 1;                       // Player get status of not dead (aka alive)
        this->interacted_with = NULL;                // Last command on another player (Nothing yet so NULL)
    }


    void Player::income(){
        this->game->validatesStart(); // Validates that the game started & has atleast 2 players
        if(this-> is_not_dead == 0){  // Verify that the current player isn't dead
            throw std::runtime_error("Dead players cannot play");
        }
        if(this-> game -> current_turn() != this-> player_name){ // Verify the current turn
            throw std::runtime_error("Not turn of " + this->player_name);
        }
        if(this-> coinsAmount >= FORCED_COUP){ // Player that has 10 coins must coup (forced coup.. duuh..)
            throw std::runtime_error("must coup with more than 10 coins");
        }
        this->coinsAmount++;                // Incerement coins amount by 1
        this->game->startGame();            // Start that game
        this->nextPlayer();                 // Turn has ended now next player's turn
    }

    void Player::foreign_aid(){
        this->game->validatesStart(); // Validates that the game started & has atleast 2 players
        if(this-> is_not_dead == 0){  // Verify that the current player isn't dead
            throw std::runtime_error("Dead players cannot play");
        }
        if(this-> game -> current_turn() != this-> player_name){ // Verify the current turn
            throw std::runtime_error("Not turn of " + this->player_name);
        }
        if(this-> coinsAmount >= FORCED_COUP){ // Player that has 10 coins must coup (forced coup.. duuh..)
            throw std::runtime_error("Player " + this->player_name + " must do a coup because he have too many coins");
        }

        this->game->startGame(); // Start the game
        this->coinsAmount += 2;  // Adds 2 coins
        this->current_command = "Foreign_aid";  // In case Duke wants to block the current player from getting 2 coins
        this->nextPlayer();     // Next turn
    }

    void Player::coup(Player &a){
        this->game->validatesStart(); // Validates that the game started & has atleast 2 players
        if(this-> is_not_dead == 0 || a.is_not_dead == 0){ // Verify that the current player isn't dead
            throw std::runtime_error("Dead players cannot play");
        }
        if(this->game->current_turn() != this-> player_name){ // Verify the current turn
            throw std::runtime_error("Not turn of " + this->player_name);
        }
        if(this->coinsAmount < COUP){ // Player does not have enough coins
            throw std::runtime_error("Cannot coup, not enough coins");
        }
        this->coinsAmount -= COUP;      // The player coins reduced by 7
        a.is_not_dead = 0;              // Player a got coup'd 
        
        game->notDead() == 1 ? game->endGame() : this->nextPlayer(); // Amount of alive players are 1? end game else change turn
    }

    std::string Player::role() const{

        return this->title;
    }

    int Player::coins() const{

        return this->coinsAmount;
    }

    void Player::nextPlayer() const{
        bool flag = true;
        while(flag){
            this->game->player_idx++; // Increment the next player
            if(this->game->list_of_players[this->game->player_idx%this->game->list_of_players.size()]->is_not_dead == 1){ // Check for the next alive player using modular arithmetics (1%6..2%6..3%6 etc..)
                flag = false;
            }
        } 
    }
}