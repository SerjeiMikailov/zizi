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
#include <ncurses.h>

extern "C"
{
#include "Reworks.h"
#include "Sysinfo.h"
}

void execute_command(const std::vector<std::string>& args);

void layout_change();
