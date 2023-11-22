#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

void cd(const char* directory)
{
    if (directory == NULL)
    {
        puts("Type the directory to access with 'cd'");
        return;
    }
    if (chdir(directory) != 0)
    {
        puts("Error accessing the directory");
    }
}
