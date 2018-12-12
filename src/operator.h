#pragma once
#include "base.h"

class Operator : public Base {
    public:
    Base* l_node;
    Base* r_node;

    /* Constructors */
    Operator() : Base() {
    	l_node = NULL;
	    r_node = NULL;
    }
    Operator(Base* l_node, Base* r_node) : Base() {
        this->l_node = l_node;
	    this->r_node = r_node;
    }
    bool execute() { return 0; }
    void set_redirect_params(int f, int t){}; //Do Nothing

    void setLeftNode(Base* left) { l_node = left; }
    void setRightNode(Base* right) { r_node = right; }

};