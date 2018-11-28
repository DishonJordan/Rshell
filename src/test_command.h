#pragma once
#include "command.h"
#include <iostream>
#include "sys/stat.h"

class TestCommand : public Command {
  private:
    // Set up for stat()
    struct stat buf;

  public:
    /* Constructors */
    TestCommand() : Command() {}
    TestCommand(vector<char*> cmd) : Command(cmd) {}

    /* Pure Virtual definition */
    bool execute() {
	 char* file_path = cmd.back();
	 int result = stat(file_path, &buf);

	if(cmd.size() > 1){
        // Check for the directory flag
            if (strcmp(cmd[1], "-d") == 0) {
                if (S_ISDIR(buf.st_mode)) {
                    print_true();
                    return 1;
                }
                else {
                    print_false();
                    return 0;
                }
            }

            // Check for the regular file flag
            else if (strcmp(cmd[1], "-f") == 0) {
                if (S_ISREG(buf.st_mode)) {
                    print_true();
                    return 1;
                }
                else {
                    print_false();
                    return 0;
                }
            }

            // Default to -e flag if not specified
            else {
                if (result == 0) {
                    print_true();
                    return 1;
                }
                else {
                    print_false();
                    return 0;
                }
            }

            return 1; // If this point is reached, the test must have passed
     }else{
        std::cout << "ERROR: TEST COMMAND NOT VALID" << endl;
	return 0;
     }
    }

    // Print methods 
    void print_true() { std::cout << "(True)" << std::endl; }
    void print_false() { std::cout << "(False)" << std::endl; }
};
