#include "Player.hpp"
#include "Game.hpp"


namespace coup{

    /**
     * @brief Ambassador header file
     * 
     */
    class Ambassador : public Player{

        public:
            /**
             * @brief Construct a new Ambassador object
             * 
             * @param _game 
             * @param name 
            */
            Ambassador(Game &_game, const std::string& name);

            /**
             * @brief Transfer a coin from a player to another
             * 
             * @param a 
             * @param b 
             */
            void transfer(Player &a, Player &b);

            /**
             * @brief Blocks captain from stealing coins
             * 
             * @param jack_sparrow (captain jack!) 
             */        
            void block(Player &jack_sparrow); 
    };
}
