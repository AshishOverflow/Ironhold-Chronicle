#include "Console.hpp"
#include <iostream>
void Console::display(){
    string buf;
    int ch;
    do{
        cout<<"ironhold>";
        getline(cin,buf);
        store(buf);
        if (buf[0] != '.')
        {
            cout<<"[World command queued: "<<buf<<"]\n";
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