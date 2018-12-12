#pragma once

class Base {
  public:
    Base() {}
    virtual bool execute() = 0;
    virtual void set_redirect_params(int f, int t) = 0;
};    
