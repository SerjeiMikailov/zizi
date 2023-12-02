#include "App.hpp"
#include "../config/config.hpp"
#include <iostream>
#include <readline/readline.h>
#include <readline/history.h>

/*
----------------------------------
|                                |
|             ZiziSh             |
|                                |
|          Version 1.3           |
|                                |
----------------------------------

First build version
Stable v1.3

*/

int main()
{
    system("clear");

    while (true)
    {
        Config::layout_change();

        char *input = readline(" -> ");
        if (!input)
        {
            std::cout << std::endl;
            break;
        }

        if (input[0] != '\0')
            add_history(input);

        std::istringstream iss(input);
        std::vector<std::string> args;

        while (iss >> input)
        {
            args.push_back(input);
        }

        execute_command(args);

        free(input);
    }

    return 0;
}
