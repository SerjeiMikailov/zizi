#include "App.hpp"
#include "../config/config.hpp"

/*
----------------------------------
|                                |
|             ZiziSh             |
|                                |
|          Version 1.2           |
|                                |
----------------------------------

First build version
Stable v1.2

*/

int main() 
{
    std::string input;
    
    system("clear");    

    while (true) 
    { 
        Config::layout_change();

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
