/* value.h */

#ifndef __VALUE_H
#define __VALUE_H
#include <iostream>
#include "base.h"

class Value : public Base {
public:
    Value(double);
    void print(ostream&) const;
    double eval() const;
    double val;

	void subst(char, const Handle&);
};

#endif // __VALUE_H
