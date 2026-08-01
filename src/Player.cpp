#include "Player.hpp"
#include <cstdint>

uint32_t Player::getId(){
    return id;
}

std::string Player::getUsername(){
    return username;
}

std::string Player::getEmail(){
    return email;
}

void Player::setId(uint32_t user_id){
    id = user_id;
}

void Player::setUsername(std::string u_username){
    username = u_username;
    username.resize(32,'\0');
}

void Player::setEmail(std::string u_email){
    email = u_email;
    username.resize(255,'\0');
}