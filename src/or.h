#pragma once
#include "operator.h"

class Or: public  Operator {
    public:
	Or() :Operator() {}
	Or(Base* left, Base* right) :Operator(left,right) {}

	bool execute() {
		
		if (!l_node->execute()) {
		  if (!r_node->execute()) {
		    return false;
		  }

		}

		return true;

	}



};
