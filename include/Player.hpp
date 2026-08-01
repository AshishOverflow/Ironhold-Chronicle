#pragma once

#include <cstdint>
#include <string>
using namespace std;
class Player{
    private:
        uint32_t id;
        string username;
        string email;
    public:
        Player(uint32_t user_id,string u_username,string u_email)
        {
            setId(user_id);
            setUsername(u_username);
            setEmail(u_email);
        }
        uint32_t getId();
        string getUsername();
        string getEmail();
        void setId(uint32_t user_id);
        void setUsername(string u_username);
        void setEmail(string u_email);
};