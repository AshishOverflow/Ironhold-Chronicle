#pragma once

#include <cstdint>
#include <string>
class Player{
    private:
        uint32_t id;
        std::string username;
        std::string email;
    public:
        Player(uint32_t user_id,std::string u_username,std::string u_email)
        {
            setId(user_id);
            setUsername(u_username);
            setEmail(u_email);
        }
        uint32_t getId();
        std::string getUsername();
        std::string getEmail();
        void setId(uint32_t user_id);
        void setUsername(std::string u_username);
        void setEmail(std::string u_email);
};