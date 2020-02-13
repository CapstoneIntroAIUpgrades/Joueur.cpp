// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../unit.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../game_object.hpp"
#include "../job.hpp"
#include "../player.hpp"
#include "../tile.hpp"
#include "../unit.hpp"
#include "coreminer.hpp"

#include <type_traits>

namespace cpp_client
{

namespace coreminer
{

bool Unit_::build(const Tile& tile, const std::string& type)
{
    std::string order = R"({"event": "run", "data": {"functionName": "build", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += std::string(",\"type\":") + std::string("\"") + type + "\"";

    order += "}}}";
    Coreminer::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Coreminer::instance()->handle_response();
    } while(info->type() == typeid(bool));
    auto doc = info->as<rapidjson::Document*>();
    auto loc = doc->FindMember("data");
    if(loc == doc->MemberEnd())
    {
       return {};
    }
    auto& val = loc->value;
    Any to_return;
    morph_any(to_return, val);
    return to_return.as<bool>();
}

bool Unit_::dump(const Tile& tile, const std::string& material, int amount)
{
    std::string order = R"({"event": "run", "data": {"functionName": "dump", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += std::string(",\"material\":") + std::string("\"") + material + "\"";

    order += std::string(",\"amount\":") + std::to_string(amount);

    order += "}}}";
    Coreminer::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Coreminer::instance()->handle_response();
    } while(info->type() == typeid(bool));
    auto doc = info->as<rapidjson::Document*>();
    auto loc = doc->FindMember("data");
    if(loc == doc->MemberEnd())
    {
       return {};
    }
    auto& val = loc->value;
    Any to_return;
    morph_any(to_return, val);
    return to_return.as<bool>();
}

bool Unit_::mine(const Tile& tile, int amount)
{
    std::string order = R"({"event": "run", "data": {"functionName": "mine", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += std::string(",\"amount\":") + std::to_string(amount);

    order += "}}}";
    Coreminer::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Coreminer::instance()->handle_response();
    } while(info->type() == typeid(bool));
    auto doc = info->as<rapidjson::Document*>();
    auto loc = doc->FindMember("data");
    if(loc == doc->MemberEnd())
    {
       return {};
    }
    auto& val = loc->value;
    Any to_return;
    morph_any(to_return, val);
    return to_return.as<bool>();
}

bool Unit_::move(const Tile& tile)
{
    std::string order = R"({"event": "run", "data": {"functionName": "move", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += "}}}";
    Coreminer::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Coreminer::instance()->handle_response();
    } while(info->type() == typeid(bool));
    auto doc = info->as<rapidjson::Document*>();
    auto loc = doc->FindMember("data");
    if(loc == doc->MemberEnd())
    {
       return {};
    }
    auto& val = loc->value;
    Any to_return;
    morph_any(to_return, val);
    return to_return.as<bool>();
}

bool Unit_::upgrade(const std::string& attribute)
{
    std::string order = R"({"event": "run", "data": {"functionName": "upgrade", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"attribute\":") + std::string("\"") + attribute + "\"";

    order += "}}}";
    Coreminer::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Coreminer::instance()->handle_response();
    } while(info->type() == typeid(bool));
    auto doc = info->as<rapidjson::Document*>();
    auto loc = doc->FindMember("data");
    if(loc == doc->MemberEnd())
    {
       return {};
    }
    auto& val = loc->value;
    Any to_return;
    morph_any(to_return, val);
    return to_return.as<bool>();
}


Unit_::Unit_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"bombs", Any{std::decay<decltype(bombs)>::type{}}},
        {"buildingMaterials", Any{std::decay<decltype(building_materials)>::type{}}},
        {"dirt", Any{std::decay<decltype(dirt)>::type{}}},
        {"health", Any{std::decay<decltype(health)>::type{}}},
        {"job", Any{std::decay<decltype(job)>::type{}}},
        {"miningPower", Any{std::decay<decltype(mining_power)>::type{}}},
        {"moves", Any{std::decay<decltype(moves)>::type{}}},
        {"ore", Any{std::decay<decltype(ore)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
        {"tile", Any{std::decay<decltype(tile)>::type{}}},
    },
    bombs(variables_["bombs"].as<std::decay<decltype(bombs)>::type>()),
    building_materials(variables_["buildingMaterials"].as<std::decay<decltype(building_materials)>::type>()),
    dirt(variables_["dirt"].as<std::decay<decltype(dirt)>::type>()),
    health(variables_["health"].as<std::decay<decltype(health)>::type>()),
    job(variables_["job"].as<std::decay<decltype(job)>::type>()),
    mining_power(variables_["miningPower"].as<std::decay<decltype(mining_power)>::type>()),
    moves(variables_["moves"].as<std::decay<decltype(moves)>::type>()),
    ore(variables_["ore"].as<std::decay<decltype(ore)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>()),
    tile(variables_["tile"].as<std::decay<decltype(tile)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Unit_::~Unit_() = default;

void Unit_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Unit treated as a vector, but it is not a vector.");
}

void Unit_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Unit treated as a vector, but it is not a vector.");
}

void Unit_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Unit treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Unit_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Unit treated as a map, but it is not a map.");
}

bool Unit_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Unit_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "job")
   { 
      to_change->as<Job>() = std::static_pointer_cast<Job_>(ref);
      return;
   }
   if(member == "owner")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
      return;
   }
   if(member == "tile")
   { 
      to_change->as<Tile>() = std::static_pointer_cast<Tile_>(ref);
      return;
   }
   try
   {
      Game_object_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Unit treated as a reference, but it is not a reference.");
}


} // coreminer

} // cpp_client