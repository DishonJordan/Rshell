#pragma once
#include "base.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class Command : public Base {
  protected:
    vector<char*> cmd;

  public:
    /* default constructor */
    Command() : Base() {} 

    /* constructor */
    Command(vector<char*> cmd) : Base(), cmd(cmd) {}

    bool execute() {
	    if(!cmd.empty()){ // Check for the empty command    
            cmd.push_back(NULL);
	        pid_t pid = fork(); // Creating the child with fork()

   	        if (strcmp(cmd[0], "exit") == 0) { // Check for the exit command
                exit(0);
            }
        
            if (pid < 0) { // Check if fork() returned an error
                perror("fork ERROR");
                return 0;
            }
	        
            if (pid == 0) {  // Override the child process with execvp syscall
	            execvp(cmd[0], cmd.data());
	            perror("execvp ERROR");  // This line will be skipped if successfull
                return 0;  // This line will be skipped if successfull
	        }
	        
            waitpid(pid, NULL, 0);  // Wait for the child process to terminate
        }

        return 1;  // Return true if successfull
    }

    void add(char* c) {
	cmd.push_back(c);
    }    
};
