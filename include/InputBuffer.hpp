#pragma once

#include <vector>
#include <string>

class InputBuffer{
    private:
    std::vector<std::string> history;
    public:
    void operator()(const std::string& input);
    int get_size();
    void display();
};
