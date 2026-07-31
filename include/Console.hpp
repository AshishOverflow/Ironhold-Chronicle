#include <string>
#include <map>
#include "InputBuffer.hpp"
using namespace std;

class Console
{
    private:
    map<string,int> m{{".quit",1},{".help",2},{".version",3},{".status",4},{".history",5}};
    InputBuffer store;
    public:
    void display();
    
};