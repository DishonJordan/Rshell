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
};
