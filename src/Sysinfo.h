#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/resource.h>

#ifndef SYSINFO_H
#define SYSINFO_H

extern void print_os();
extern void getProcessorInfo();
extern void getProcessorCores();
extern void print_processor_arch();
extern void print_memory_usage();
extern char* get_user();
extern char* working_dir();
extern void layout();

#endif

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif
