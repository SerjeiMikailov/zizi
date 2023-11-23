#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>

extern "C"
{
#include "Reworks.h"
#include "Sysinfo.h"
}

void execute_command(const std::vector<std::string>& args);
