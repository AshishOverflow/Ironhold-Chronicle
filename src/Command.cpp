#include "Command.hpp"
#include <iostream>
#include <sstream>

bool Command::validateCommand(){
    stringstream ss(cmd);
    string word;
    while(ss>>word){
        tokens.push_back(word);
    }
    if (tokens[0] == "SPAWN" && tokens[1] == "PLAYER")
    {
        if (tokens.size()!=5)
        {
            cout<<"Error: Invalid Command Syntax.";
            return false;
        }
        return validateId((tokens[2])) && validateUsername(tokens[3]) && validateEmail(tokens[4]);
    }
    else if (tokens[0] == "LIST" && tokens[1] == "PLAYERS")
        return true;
    return false;
}

bool Command::validateId(string id){
    int val = stoi(id);
    if (val <= 0)
    {
        cout<<"Error: ID must be positive.\n";
        return false;
    }
    return true;
}

bool Command::validateUsername(string username){
    auto length = username.length();
    if (length > 32)
    {
        cout<<"Error: username too long (max 32 chars).\n";
        return false;
    }
    return true;
}

bool Command::validateEmail(string email)
{
    auto length = email.length();
    if (length > 255)
    {
        cout<<"Error: email too long (max 255 chars).\n";
        return false;
    }
    return true;
}

vector<string> Command::getTokens() const{
    return tokens;
}
