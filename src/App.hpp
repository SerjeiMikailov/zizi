/*

  Zizi_Shell main header file.
  This header contains all stdlibs used in ZZsh.
  Config system files are also linked with this header.

*/

// Bunch of std lib includes
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <fstream>
#include <thread>
#include <chrono>
#include <future>
#include <ctime>
#include <iomanip>

#include <readline/readline.h>
#include <readline/history.h>


// ShellB C functions in Zizi_Shell
extern "C"
{
#include "Reworks.h"
#include "Sysinfo.h"
}

// C++ Functions previous implemented in cpp files
//
// Used in main.cpp to run the commands written in commands.cpp
void execute_command(const std::vector<std::string>& args);
//
// Implemented in Confi.hpp to change and show the shell layout
void layout_change();
//
// ASCII print to clean the shell screen
void clear();
