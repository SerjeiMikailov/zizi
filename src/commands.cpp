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
        std::cout << "Zizi_Shell v1.2" << std::endl;
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
    else if (args[0] == "cd")
    {
        if (args.size() < 2)
        {
            std::cout << "Usage: cd <directory>" << std::endl;
        }
        else
        {
            // Convert string to const char*
            const char *directory = args[1].c_str();
            cd(directory);
        }
    }
    else if (args[0] == "clear")
    {
      system("clear"); 
    }
    else
    {
        std::string fullCommand;
        for (const auto &arg : args)
        {
            fullCommand += arg + " ";
        }

        FILE *pipe = popen(fullCommand.c_str(), "r");
        if (!pipe)
        {
            std::cerr << "Error executing command." << std::endl;
            return;
        }

        char buffer[128];
        std::string result = "";

        while (!feof(pipe))
        {
            if (fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }

        pclose(pipe);

        std::cout << result << std::endl;
    }
}
