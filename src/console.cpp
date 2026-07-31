#include </home/24pc03/chronicle/include/application_state.hpp>

class InputBuffer{
    private:
    vector<string> history;
    public:
    string operator()(const string& input) 
    { 
        return input;
    }
};
class Console
{
    private:
    map<string,int> m{{".quit",1},{".help",2},{".version",3},{".status",4}};
    public:
    void display(){
        string buf;
        int ch;
        do{
            cout<<"ironhold>";
            getline(cin,buf);
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
                    cout<<".quit\tShut down the world engine\n.help\tShow this message\n.version\tShow engine version\n.status\tShow world status\n";
                    break;
                case 3:
                    cout<<"Chronicle v0.1 — Ironhold World Engine\n";
                    break;
                case 4:
                    cout<<"World: offline\n";
                    break;
                default:
                    cout<<"AppState::UNKNOWN\n";
                    break;
            }
        }while(buf != ".quit");
    }
};