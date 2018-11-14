#pragma once
#include "base.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include  <stdio.h>

using namespace std;

class Command : public Base {
  private:
    vector<char*> cmd;

  public:
    /* default coiinstructor */
    Command() : Base() {}

    /* constructor */
    Command(vector<char*> cmd) : Base(), cmd(cmd) {}

    bool execute() {
	
	/* create the child */
        pid_t pid = fork();

        /* perror if fork error */
        if (pid < 0) {
            perror("fork ERROR");
            return 0;
        }

	/* override the child process */
	if (pid == 0) {
	    execvp(cmd[0], cmd.data());
	    perror("execvp ERROR");
	}

        /* wait for the child to terminate */
	waitpid(pid, NULL, 0);
  
    	return 1;
    }

	void add(char* c) {
		cmd.push_back(c);
	}
};
