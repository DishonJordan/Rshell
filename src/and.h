#pragma once
#include "operator.h"

class And: public  Operator {
    public:
	And() :Operator() {}
	And(Base* left, Base* right) : Operator(left, right) {}

	bool execute() {
		if (l_node->execute()) {

			if(r_node->execute())
				return true;
		}

		return false;

	}



};
