#include "Player.hpp"
#include <cstdint>

uint32_t Player::getId(){
    return id;
}

string Player::getUsername(){
    return username;
}

string Player::getEmail(){
    return email;
}

void Player::setId(uint32_t user_id){
    id = user_id;
}

void Player::setUsername(string u_username){
    username = u_username;
}

void Player::setEmail(string u_email){
    email = u_email;
}