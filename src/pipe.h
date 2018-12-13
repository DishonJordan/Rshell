#pragma once
#include "operator.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "stdlib.h"

class Pipe : public Operator {
  public:
    Pipe() : Operator() {}
    Pipe(Base* l_node. Base* r_node) : Operator() {}

    bool execute() {
        int fds[2];

        if (pipe(fds) == -1) {
	    perror("pipe");
	    return 0;
	}

	if (!l_node->execute())
	    return 0;

	close(fds[1]);

	if (!r_node->execute())
	    return 0;

	close(fds[0]);
	return 1;
    }
};
