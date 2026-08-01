#include "InputBuffer.hpp"
#include <iostream>

void InputBuffer::operator()(const string& input) 
{ 
    history.push_back(input);
}
int InputBuffer::get_size()
{
    return history.size();
}
void InputBuffer::display()
{
    for (string s : history)
        cout << s << "\n";
}
