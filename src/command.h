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
    int redirector;
    int file_loc;

  public:
    /* default constructor */
    Command() : Base() {
        redirector = -1;
        file_loc = -1;
    } 

    /* constructor */
    Command(vector<char*> cmd) : Base(), cmd(cmd) {
        redirector = -1;
        file_loc = -1;
    }

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
                switch(redirector){
                    case 0: // Input redirect case
                        cout << "INPUT REDIRECT DETECTED" << endl;
                        if(dup2(file_loc,0) < 0){
                            perror("dup ERROR");
                            return false;
                        }
                        break;
                    case 1: //Output redirect case
                        if(dup2(file_loc,1) < 0){
                             cout << "OUTPUT REDIRECT DETECTED" << endl;
                            perror("dup ERROR");
                            return false;
                        }
                        break;
                    default: ;
                }

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

    char* get_command(){
        if(cmd.size() > 0)
            return cmd[0];
        else
            return NULL;
    }

    void set_redirect_params(int file_location, int redirect_type){
		file_loc = file_location;
		redirector = redirect_type;
			
}
};
