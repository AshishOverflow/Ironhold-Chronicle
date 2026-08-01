#pragma once

#include <string>
#include <map>
#include "Command.hpp"
#include "InputBuffer.hpp"
#include "WorldState.hpp"

class Console
{
    private:
    std::map<std::string,int> m{{".quit",1},{".help",2},{".version",3},{".status",4},{".history",5}};
    InputBuffer store;
    WorldState world;
    public:
    void display();
    void execute(const Command&,WorldState&);
};