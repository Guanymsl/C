/* term.h */

#ifndef __TERM_H
#define __TERM_H
#include "base.h"
#include "handle.h"
#include <iostream>
using namespace std;

class Term : public Base {

public:
    char op;
    Handle left, right;
    Term(char, Handle, Handle);
	void print(ostream&) const;
	void subst(char, const Handle&);
	double eval() const;
};

#endif //__TERM_H