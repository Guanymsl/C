#ifndef __HANDLE_H
#define __HANDLE_H

#include <iostream>
#include "base.h"

class Handle {
public:
    // Member variable
    Base *p;

    // Constructor and Destructor (non-default)
    Handle();
    Handle(Base *);
    Handle(const Handle&);
    ~Handle();

    // Member function
    Handle& operator= (const Handle&);
    void print(ostream&) const;
    double eval() const;
    TYPE type() const;

    void subst(char, const Handle&);

};

#endif // __HANDLE_H