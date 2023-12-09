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
private:
  static std::string LocalTime()
  {
    std::time_t currentTime;
    std::time(&currentTime);

    struct std::tm *localTime = std::localtime(&currentTime);

    if (localTime != nullptr)
    {
      std::ostringstream oss;
      oss << std::put_time(localTime, "%I:%M:%S %p"); // %I for 12-hour, %p for AM/PM

      return oss.str();
    }
    else
    {
      std::cerr << "Error getting local time\n";
      return "";
    }
  }

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
    std::cout << "\033[1;34m" << folder << "\033[0m" << std::endl;
  }

  static void Layout2()
  {
    std::string user = Get_User();
    std::string folder = Working_Dir();
    std::string time = LocalTime();

    std::cout << "\033[1;32m" << user << "@" << user << "\033[0m ";
    std::cout << "\033[1;34m" << "[" << time << "]" << "\033[0m ";
    std::cout << "\033[1;38;5;252m" << "[" << folder << "]" << "\033[0m" << std::endl;
  }
};
