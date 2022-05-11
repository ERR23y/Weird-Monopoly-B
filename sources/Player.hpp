#pragma once
#include "Game.hpp"
#include <stdexcept>
#include <string>

namespace coup{
    /**
     * @brief Basic class of "Player" object which holds the default operations the rest of the players can do
     * Each "role" inherit Player
     * 
     * P.S "forced to implement" functions were bolded by @brief 
     * 
     */
    const int FORCED_COUP = 10;  // If player holds 10 coins it should be forced coup
    const int COUP = 7;          // Minimal points for coup
    const int ASSASSIN_COUP = 3; // Assassin's coup - 3 coins
    class Game; // So I won't get weird error - cannot initialize object parameter of type 'coup::Player' with an expression of
    class Player{
        public:

            /**
            * @brief Construct a new Player object
            * 
            * @param _game 
            * @param player_name 
            */
            Player(Game &game, const std::string& player_name);

            Game *game;
            std::string player_name;                // Name of each player
            std::string title;                      // Role of each player
            int coinsAmount;                        // Amount of coins each player holds
            std::string current_command;            // Holds the current special command of the current player - Captain steal, Assassin coup etc..
            int is_not_dead;                        // For some reason boolean cause tons of errors. 1 true, 0 false
            Player *interacted_with;                // Last player to do a method on : Assassin used steal on Duke
            
            /**
             * @brief Grants the player a single coin
             * 
             */
            void income();   

            /**
             * @brief Grants the player 2 coins (Can be blocked)
             * 
             */                                  
            void foreign_aid();

            /**
             * @brief End another player's live! 
             * Assassin's require 3 coins and the rest 7.
             * If a player holds 10 coins the coup() starts automatically
             * 
             * virtual so it can be implemented differently in assassin.cpp
             * @param b 
             */
            virtual void coup(Player &a);
            
            /**
            * @brief Role of the player
            * 
            * @return std::string 
            */
            std::string role() const;               
            
            /**
            * @brief Amount of coins the player has
            * 
            * @return int 
            */
            int coins() const;

            // ---- Helping functions -----                     
            void nextPlayer() const;                // Switch to next player in line (End of the turn)
    };
}
