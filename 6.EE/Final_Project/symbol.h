/* symbol.h */

#ifndef __SYMBOL_H
#define __SYMBOL_H

#include "base.h"
#include <iostream>
using namespace std;

class Symbol : public Base {

public:
    Symbol(char);
	void print(ostream&) const;
	void subst(char, const Handle&);
	double eval() const;

    char sym;

};

#endif // __SYMBOL_H