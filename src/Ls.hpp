#include <iostream>
#include <cstring>
#include <dirent.h>
#include <iomanip>
#include <unistd.h>

class FileOperations
{
public:
    static void listDirectory(const char *path)
    {
        DIR *dir = opendir(path);

        if (dir == NULL)
        {
            std::cout << "Error to open the directory" << std::endl;
            return;
        }

        int maxNameLength = getMaxNameLength(dir, path);

        rewinddir(dir);

        printDirectoryContents(dir, maxNameLength);

        closedir(dir);
    }

private:
    static int getMaxNameLength(DIR *dir, const char *path)
    {
        int maxNameLength = 0;
        struct dirent *entry;

        while ((entry = readdir(dir)) != NULL)
        {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                char fullPath[PATH_MAX];
                snprintf(fullPath, PATH_MAX, "%s/%s", path, entry->d_name);
                int nameLength = strlen(fullPath);
                if (nameLength > maxNameLength)
                {
                    maxNameLength = nameLength;
                }
            }
        }

        return maxNameLength;
    }

    static void printDirectoryContents(DIR *dir, int maxNameLength)
    {
        struct dirent *entry;

        while ((entry = readdir(dir)) != NULL)
        {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                std::cout << std::left << std::setw(maxNameLength + 2) << entry->d_name << std::endl;
            }
        }
    }
};