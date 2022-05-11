#include "Game.hpp"

namespace coup{
    
    Game::Game(){
        this-> player_idx = 0;
        this-> start = false;
        this-> end = false;
    }

    std::vector<std::string> Game::players(){
        std::vector<std::string> res;
        for(auto& idx : this->list_of_players){
            if(idx->is_not_dead == 1){ // Is players status not dead?
                res.push_back(idx->player_name);
            }
        }
        return res;
    }

    std::string Game::current_turn(){
        std::string name;
        name = this->list_of_players[this->player_idx % this->list_of_players.size()]->player_name; // Modular arithmetic
        return name;
    }

    std::string Game::winner(){
            if (this->players().size() > 1 || !this->hasEnded()){ // High amount of living players OR game has not ended
                throw std::runtime_error("Cannot declare a winner yet!");
            }

            std::string winner_name;
            for(auto& player : list_of_players){
                if (player->is_not_dead == 1) // Only one player is alive
                {
                    winner_name = player->player_name;
                    break;
                }
                
            }
            return winner_name;
    }
    bool Game::goinOn() const{
        return this->start;    
    }

    bool Game::hasEnded() const {
        return this->end;
    }

    int Game::notDead(){
        int amount = 0; // Count the living
        for(auto& idx : this->list_of_players){
            if(idx->is_not_dead == 1){ 
                amount++;
            }
        }
        return amount;
    }

    void Game::endGame(){
        this->end = true;
    }
    void Game::startGame(){
        this ->start = true;
    }

    void Game::validatesStart(){
        if (this->players().size() < MIN_PLAYERS && !this->goinOn()){
            throw std::runtime_error("Game has less than 2 players");
        }
    }
}