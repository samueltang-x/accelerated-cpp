#ifndef GUARD_Grad_h
#define GUARD_Grad_h

#include "Core.h"

class Grad: public Core {
  public:
    Grad(): thesis(0) {}
    Grad(std::istream& is) { read(is); }

    std::istream& read(std::istream&);
    double grade() const;

  private:
    double thesis;
};

#endif
