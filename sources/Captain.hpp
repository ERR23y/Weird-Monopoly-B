#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    /**
     * @brief Captain header file
     * 
     */
    class Captain : public Player{

        public:
        /**
        * @brief Construct a new Captain object
        * 
        * @param _game 
        * @param player_name 
        */
        Captain(Game &_game, const std::string& name);

        /**
        * @brief Prevent other captain of using steal()
        * 
        * @param a 
        */
        void block(Player &a);

        /**
         * @brief Steal 2 coins from another player
         * 
         * @param a 
         */
        void steal(Player &a);


            
    };
}
