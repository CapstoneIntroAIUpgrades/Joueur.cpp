// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "amazons.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace amazons
{

//register the game
Game_registry registration("Amazons",
                           "1b2ac0db4655c0c135ffbf80607a97ab5434b880e1b76f1ade9fdaf44670ae23",
                           std::unique_ptr<Amazons>(new Amazons));

std::unique_ptr<Base_ai> Amazons::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Amazons::generate_object(const std::string& type)
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

} // amazons

} // cpp_client
