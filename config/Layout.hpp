#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <fstream>
#include <unistd.h>

class Layout
{
public:
  static std::string Get_User()
  {
    const char *user = getenv("USER");
    return (user != nullptr) ? user : "";
  }

  static std::string Working_Dir()
  {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
      return std::string(cwd);
    }
    else
    {
      perror("getcwd() error");
      return std::string("");
    }
  }

  static void Layout1()
  {
    std::string user = Get_User();
    std::string folder = Working_Dir();

    std::cout << "\033[1;32m" << user << "\033[0m:";
    std::cout << "\033[1;34m" << folder << "\033[0m -> ";
  }
};
