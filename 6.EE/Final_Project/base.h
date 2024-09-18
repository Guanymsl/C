
#ifndef _BASE_H_
#define _BASE_H_

#include <iostream>
using namespace std;

enum TYPE {
	VALUE,
	SYMBOL,
	TERM
};

class Handle;

class Base {

protected:
	// Constructor (default)
	Base();
	// Copy assignment operator
	Base& operator= (const Base&);

public:
	// Virtual destructor
	virtual ~Base() {}
	// Pure virtual function
	virtual void print(ostream&) const = 0;
	virtual double eval() const = 0;
	virtual void subst(char, const Handle&) = 0;
	// Data member
	int use;
	TYPE type;
};

#endif // _BASE_H_
