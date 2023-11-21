#include <iostream>
#include <cstdio>
#include <cstring>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

class Rm {
public:
    static void remove(const char* path) {
        if (path == nullptr) {
            std::cerr << "Type the name of the file/directory to remove with 'remove'" << std::endl;
            return;
        }

        struct stat st;
        if (lstat(path, &st) == -1) {
            std::cerr << "Error getting file/directory information" << std::endl;
            return;
        }

        if (S_ISDIR(st.st_mode)) {
            removeDirectory(path);
        } else {
            if (std::remove(path) != 0) {
                std::cerr << "Error removing file: " << path << std::endl;
            }
        }
    }

private:
    static void removeDirectory(const char* path) {
        DIR* dir = opendir(path);

        if (dir == nullptr) {
            std::cerr << "Error opening directory: " << path << std::endl;
            return;
        }

        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                std::string fullPath = std::string(path) + "/" + entry->d_name;
                remove(fullPath.c_str());
            }
        }

        closedir(dir);

        if (rmdir(path) != 0) {
            std::cerr << "Error removing directory: " << path << std::endl;
        }
    }
};