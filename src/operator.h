#include "base.h"

class Operator : public Base {
  protected:
    Base* l_node;
    Base* r_node;

  public:
    /* Constructors */
    Operator() : Base() {}
    Operator(Base* l_node, Base* r_node) : Base() {
        this->l_node = l_node;
		this->r_node = r_node;
    }
	//For testing purposes, this will later be virtual
	virtual bool execute() {
		l_node->execute();
		r_node->execute();
	}

	void setLeftNode(Base* left) { l_node = left; }
	void setRightNode(Base* right) { r_node = right; }
};
