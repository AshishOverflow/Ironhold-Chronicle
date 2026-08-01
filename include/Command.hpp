#pragma once

#include <string>
#include <vector>
using namespace std;
class Command{
    private:
    string cmd;
    vector<string> tokens;
    public:
    Command(string u_cmd){
        cmd = u_cmd;
    }
    bool validateCommand();
    bool validateId(string id);
    bool validateUsername(string username);
    bool validateEmail(string email);
    vector<string> getTokens() const;
};