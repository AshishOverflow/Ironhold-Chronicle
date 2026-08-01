#include "InputBuffer.hpp"
#include <iostream>

void InputBuffer::operator()(const std::string& input) 
{ 
    history.push_back(input);
}
int InputBuffer::get_size()
{
    return history.size();
}
void InputBuffer::display()
{
    for (std::string s : history)
        std::cout << s << "\n";
}
