#include "Player.hpp"
#include "Game.hpp"


namespace coup{
    /**
     * @brief Duke header file
     * 
     */
    class Duke:public Player{
        public:
            /**
            * @brief Construct a new Duke object
            * 
            * @param _game 
            * @param name 
            */
            Duke(Game &_game, const std::string &name);
            
            /**
             * @brief Block foreign_aid() and returns 2 coins to the general pile of coins in Game
             * 
             * @param a 
             */
            void block(Player &a);

            /**
             * @brief Duke can take 3 coins with no interrupts from anyone
             * 
             */
            void tax();
            

    };
}
