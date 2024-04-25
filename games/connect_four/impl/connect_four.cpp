// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "connect_four.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace connect_four
{

//register the game
Game_registry registration("Connect_four",
                           "ff3da34375459be10b77fd8f82b24d9880f0a100e48e2202812118bfcfd42e1e",
                           std::unique_ptr<Connect_four>(new Connect_four));

std::unique_ptr<Base_ai> Connect_four::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Connect_four::generate_object(const std::string& type)
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

} // connect_four

} // cpp_client
