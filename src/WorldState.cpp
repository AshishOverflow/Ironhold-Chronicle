#include "WorldState.hpp"
#include <iostream>
void WorldState::addPlayer(Player *p){
    players.push_back(*p);
    cout<<"Spawned.\n";
}

void WorldState::viewPlayers(){
    for(auto p:players)
    {
        cout<<"["<<p.getId()<<"]"<<" "<<p.getUsername()<<" <"<<p.getEmail()<<">"<<"\n";
    }
    cout<<players.size()<<"entities.\n";

}

vector<Player> WorldState::getPlayers()
{
    return players;
}
