// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "ultimate_tic_tac_toe.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace ultimate_tic_tac_toe
{

//register the game
Game_registry registration("Ultimate_tic_tac_toe",
                           "50e7a74ecd23f8e98bbe235fc2aa7db662a607ebdeb59ad3e5a4213cff4f8a43",
                           std::unique_ptr<Ultimate_tic_tac_toe>(new Ultimate_tic_tac_toe));

std::unique_ptr<Base_ai> Ultimate_tic_tac_toe::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Ultimate_tic_tac_toe::generate_object(const std::string& type)
{
    if(type == "GameObject")
    {
        return std::make_shared<Game_object_>();
    }
    else if(type == "Player")
    {
        return std::make_shared<Player_>();
    }
    throw Unknown_type("Unknown type " + type + " encountered.");
}

} // ultimate_tic_tac_toe

} // cpp_client
