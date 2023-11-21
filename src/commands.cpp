#include "App.hpp"
#include "Ls.hpp"
#include "Rm.hpp"

void execute_command(const std::vector<std::string> &args)
{
    if (args.empty())
    {
        std::cout << "No command provided." << std::endl;
        return;
    }

    if (args[0] == "zz" && args.size() == 2 && args[1] == "--v")
    {
        std::cout << "Zizi_Shell v1.0" << std::endl;
    }
    else if (args[0] == "ls")
    {
        char currentPath[PATH_MAX];
        if (getcwd(currentPath, sizeof(currentPath)) != NULL)
        {
            FileOperations::listDirectory(currentPath);
        }
        else
        {
            std::cout << "Error getting current working directory" << std::endl;
        }
    }
    else if (args[0] == "rm")
    {
        if (args.size() < 2)
        {
            std::cout << "Usage: rm <file/directory>" << std::endl;
        }
        else
        {
            Rm::remove(args[1].c_str());
        }
    }
    else
    {
        std::cout << "Unknown command: " << args[0] << std::endl;
    }
}
