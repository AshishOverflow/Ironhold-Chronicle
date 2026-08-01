#include "Console.hpp"
#include "Command.hpp"
#include "Player.hpp"
#include <cstdint>
#include <iostream>
#include <vector>
void Console::display(){
    string buf;
    int ch;
    do{
        cout<<"ironhold>";
        getline(cin,buf);
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
                cout<<".quit — flush open state and exit cleanly\n.help — print a summary of available commands\n.version — print Chronicle v0.1 — Ironhold World Engine\n.status — print World: offline\n";
                break;
            case 3:
                cout<<"Chronicle v0.1 — Ironhold World Engine\n";
                break;
            case 4:
                cout<<"World: offline\n";
                break;
            case 5:
                cout<<"History length: "<<store.get_size()<<"\n";
                store.display();
                break;
            default:
                cout<<"AppState::UNKNOWN\n";
                break;
        }
    }while(buf != ".quit");
}

void Console::execute(const Command& c,WorldState& w){
    vector<string> tokens = c.getTokens();
    if (tokens[0] == "SPAWN" && tokens[1] == "PLAYER")
    {
        vector<Player>players = w.getPlayers();
        for(auto p: players)
        {
            if (p.getId() == static_cast<uint32_t>(stoul(tokens[2])))
            {
                cout<<"Error: ID already exists.\n";
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
