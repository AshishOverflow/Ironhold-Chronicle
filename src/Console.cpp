#include "Console.hpp"
#include "Command.hpp"
#include "Player.hpp"
#include <cstdint>
#include <iostream>
#include <vector>
void Console::display(){
    std::string buf;
    int ch;
    do{
        std::cout<<"ironhold>";
        getline(std::cin,buf);
        store(buf);
        if (buf[0] != '.')
        {
            Command *c = new Command(buf);
            if(c->validateCommand())
            {
                execute(*c,world);
            }
            continue;
        }
        ch = m[buf];
        switch(ch)
        {
            case 1:
                return;
            case 2:
                std::cout<<".quit — flush open state and exit cleanly\n.help — print a summary of available commands\n.version — print Chronicle v0.1 — Ironhold World Engine\n.status — print World: offline\n.history - To view previous commands\n";
                break;
            case 3:
                std::cout<<"Chronicle v0.1 — Ironhold World Engine\n";
                break;
            case 4:
                std::cout<<"World: online\n";
                break;
            case 5:
                std::cout<<"History length: "<<store.get_size()<<"\n";
                store.display();
                break;
            default:
                std::cout<<"AppState::UNKNOWN\n";
                break;
        }
    }while(buf != ".quit");
}

void Console::execute(const Command& c,WorldState& w){
    std::vector<std::string> tokens = c.getTokens();
    if (tokens[0] == "SPAWN" && tokens[1] == "PLAYER")
    {
        std::vector<Player>players = w.getPlayers();
        for(auto p: players)
        {
            if (p.getId() == static_cast<uint32_t>(stoul(tokens[2])))
            {
                std::cout<<"Error: ID already exists.\n";
                return;
            }
        }
        w.addPlayer(new Player(static_cast<uint32_t>(stoul(tokens[2])),tokens[3],tokens[4]));
    }
    else if (tokens[0] == "LIST" && tokens[1] == "PLAYERS")
    {
        w.viewPlayers();
    }
}
