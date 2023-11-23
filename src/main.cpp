#include "App.hpp"

/*
----------------------------------
|                                |
|             ZiziSh             |
|                                |
|          Version 1.0           |
|                                |
----------------------------------

First build version
Stable v1

*/

int main() 
{
    std::string input;

    while (true) 
    {
        layout();

        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::vector<std::string> args;

        while (iss >> input) 
        {
            args.push_back(input);
        }

        execute_command(args);
    }

    return 0;
}
