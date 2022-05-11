#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    /**
     * @brief Contessa header file
     * 
     */
    class Contessa : public Player{

        public:
            /**
             * @brief Construct a new Contessa object
             * 
             * @param _game 
             * @param player_name 
             */
            Contessa(Game &_game, const std::string& name);

            /**
             * @brief Prevents assassin's 3 coins coup
             * 
             * @param a 
             */
            void block(Player &a);
    };
}
