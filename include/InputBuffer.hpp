#pragma once

#include <vector>
#include <string>
using namespace std;

class InputBuffer{
    private:
    vector<string> history;
    public:
    void operator()(const string& input);
    int get_size();
    void display();
};
