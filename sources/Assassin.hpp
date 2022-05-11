#include "Game.hpp"
#include "Player.hpp"


namespace coup{
    /**
     * @brief Assassin header file
     * 
     */
    class Assassin:public Player{
        public:
            /**
             * @brief Construct a new Assassin object
             * 
             * @param _game 
             * @param name 
             */
            Assassin(Game &_game, const std::string& name);

            /**
             * @brief Can coup another player with 3 coins
             * 
             * @param a 
             */
            void coup(Player &a);   
    };
}
