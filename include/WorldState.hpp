#pragma once

#include <vector>
#include "Player.hpp"

class WorldState{
    private:
        std::vector<Player> players;
    public:
        void addPlayer(Player *p);
        void viewPlayers();
        std::vector<Player> getPlayers();
};