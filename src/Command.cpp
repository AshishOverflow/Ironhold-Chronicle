#include "Command.hpp"
#include <iostream>
#include <sstream>

bool Command::validateCommand(){
    std::stringstream ss(cmd);
    std::string word;
    while(ss>>word){
        tokens.push_back(word);
    }
    if (tokens[0] == "SPAWN" && tokens[1] == "PLAYER")
    {
        if (tokens.size()!=5)
        {
            std::cout<<"Error: Invalid Command Syntax.";
            return false;
        }
        return validateId((tokens[2])) && validateUsername(tokens[3]) && validateEmail(tokens[4]);
    }
    else if (tokens[0] == "LIST" && tokens[1] == "PLAYERS")
        return true;
    return false;
}

bool Command::validateId(std::string id){
    int val = stoi(id);
    if (val <= 0)
    {
        std::cout<<"Error: ID must be positive.\n";
        return false;
    }
    return true;
}

bool Command::validateUsername(std::string username){
    auto length = username.length();
    if (length > 32)
    {
        std::cout<<"Error: username too long (max 32 chars).\n";
        return false;
    }
    return true;
}

bool Command::validateEmail(std::string email)
{
    auto length = email.length();
    if (length > 255)
    {
        std::cout<<"Error: email too long (max 255 chars).\n";
        return false;
    }
    return true;
}

std::vector<std::string> Command::getTokens() const{
    return tokens;
}
