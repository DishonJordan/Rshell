#pragma once
#include "command.h"
#include <iostream>
#include "sys/stat.h"

bool Command::test_command() {
    // Set up for stat()
    struct stat buf;
    char* file_path = cmd.back();
    int result = stat(file_path, &buf);


    // Check for the directory flag
    if (strcmp(cmd[1], "-d") == 0) {
        if (S_ISDIR(buf.st_mode)) {
            std::cout << "(True)" << std::endl;
            return 1;
        }
        else {
            std::cout << "(False)" << std::endl;
            return 0;
        }
    }

    // Check for the regular file flag
    else if (strcmp(cmd[1], "-f") == 0) {
        if (S_ISREG(buf.st_mode)) {
            std::cout << "(True)" << std::endl;
            return 1;
        }
        else {
            std::cout << "(False)" << std::endl;
            return 0;
        }
    }

    // Default to -e flag if not specified
    else {
        if (result == 0) {
            std::cout << "(True)" << std::endl;
            return 1;
        }
        else {
            std::cout << "(False)" << std::endl;
            return 0;
        }
    }

    return 1; // If this point is reached, the test must have passed
}
