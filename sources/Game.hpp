#pragma once
#include "Player.hpp"
#include <vector>
#include <string>
#include <stdexcept>

namespace coup{
    class Player;
    const int MAX_PLAYERS = 6; // Maximal allowed players
    const int MIN_PLAYERS = 2; // Minimal allowed players
    /**
     * @brief Class of Game which holds -
     *          - A list of players
     *          - Game winner
     *          - Is the game still on?
     *          - Amount of living players
     *      
     * 
     */

    class Game{
            bool start; // Start the game
            bool end;   // End the game

        public:
            Game();                                 // Default constructor
            u_int player_idx;                       // Modular usage of index of current player instead of using 2 loops (has to walk over vector.size() which is unsigned)
            std::vector<Player*> list_of_players;   // List of the players
            std::vector<std::string> players();     // List of alive players
            std::string winner();                   // Winner of the game

            // Helping functions 

            /**
             * @brief Turn of whom?
             * 
             * @return std::string 
             */
            std::string current_turn();
            
            /**
             * @brief Has the game begun?
             * 
             * @return true 
             * @return false 
             */
            bool goinOn() const;
           
           /**
            * @brief Has the game ended?
            * 
            * @return true 
            * @return false 
            */
            bool hasEnded() const;
           
           /**
            * @brief End the game
            * 
            */
            void endGame();
            /**
             * @brief Start the game
             * 
             */
            void startGame();
            /**
             * @brief Amount of players alive
             * 
             * @return int 
             */
            int notDead();

            /**
             * @brief Validates that the game started & has atleast 2 players
             * 
             */
            void validatesStart();
    };
}
