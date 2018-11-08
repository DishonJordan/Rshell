#pragma once

class Rshell_Base {
  public:
    Rshell_Base() {}
    virtual bool execute() = 0;
};    
