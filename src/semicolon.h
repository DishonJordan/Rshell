#pragma once
#include "operator.h"

class Semicolon: public  Operator {
    public:
	Semicolon() :Operator() {}
	Semicolon(Base* left, Base* right) :Operator(left, right) {}

	bool execute() {
			
		l_node->execute();
		r_node->execute();
		
		return true;
	
	}



};
