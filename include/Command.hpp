#pragma once

#include <string>
#include <vector>

class Command{
    private:
    std::string cmd;
    std::vector<std::string> tokens;
    public:
    Command(std::string u_cmd){
        cmd = u_cmd;
    }
    bool validateCommand();
    bool validateId(std::string id);
    bool validateUsername(std::string username);
    bool validateEmail(std::string email);
    std::vector<std::string> getTokens() const;
};