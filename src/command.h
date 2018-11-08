#pragma once
#include "base.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>

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
	
	/* override the child process */
	execvp(cmd[0], cmd.data());

	/* wait for the child process */
	waitpid(pid, NULL, 0);
    
    	return 1;
    }
};
