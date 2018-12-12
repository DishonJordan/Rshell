#pragma once
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>

#include "operator.h"

class ORedirect: public  Operator {
    public:
	ORedirect() :Operator() {}
	ORedirect(Base* left, Base* right) : Operator(left, right) {}

	bool execute() {
		cout << "Opening " << ((Command*)r_node)->get_command() << endl;

		int file_index = open(((Command*)r_node)->get_command(), O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);

		if(file_index < 0){
			perror("File Not Found");
			return false;
		}

		l_node->set_redirect_params(file_index,1);

		bool result = l_node->execute();
		close(file_index);
		return result;

	  }
	
	void set_redirect_params(int f, int t){
		l_node->set_redirect_params(f,t);
	};

};