#ifndef _EXPR_H_
#define _EXPR_H_

#include "base.h"
#include "handle.h"

class Expr {
friend class Handle;
public:
	Expr(Handle);
	Expr(const Expr&);
	Expr(double);
	Expr(char);
	Expr& operator= (const Expr&);
	Expr operator+ (const Expr&) const;
	Expr operator- (const Expr&) const;
	Expr operator* (const Expr&) const;
	Expr operator/ (const Expr&) const;
	void subst(char, const Expr&);
	double eval() const;
	friend ostream& operator<< (ostream&, const Expr&);
	Handle h;
};

ostream& operator<< (ostream&, const Expr&);

#endif