#pragma once
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>

#include "operator.h"

class IRedirect: public  Operator {
    public:
	IRedirect() :Operator() {}
	IRedirect(Base* left, Base* right) : Operator(left, right) {}

	bool execute() {

		int file_index = open(((Command*)r_node)->get_command(), O_RDONLY);
		if(file_index < 0){
			perror("File Not Found");
			return false;
		}

		l_node->set_redirect_params(file_index,0);

		bool result = l_node->execute();
		close(file_index);
		return result;
	  }

	void set_redirect_params(int f, int t){
		l_node->set_redirect_params(f,t);
	};
};