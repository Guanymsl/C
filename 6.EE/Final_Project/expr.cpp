#include <iostream>
#include "expr.h"
#include "base.h"
#include "handle.h"
#include "value.h"
#include "symbol.h"
#include "term.h"
using namespace std;

void Expr::subst(char sym, const Expr& e) {
    h.subst(sym, e.h);
}

double Expr::eval() const {
    return h.eval();
}

ostream& operator<< (ostream& o, const Expr& e) {
    e.h.print(o);
    return o;
}

Expr::Expr(Handle _h) { h = _h; }

Expr::Expr(const Expr& rhs) { *this = rhs; }

Expr::Expr(double _val) { h = Handle(new Value(_val)); }

Expr::Expr(char _sym) { h = Handle(new Symbol(_sym)); }

Expr& Expr::operator=(const Expr& rhs) {

    h = rhs.h;
    return *this;

}

Expr Expr::operator+(const Expr& rhs) const { return Expr(Handle(new Term('+' , h , rhs.h))); }

Expr Expr::operator-(const Expr& rhs) const { return Expr(Handle(new Term('-' , h , rhs.h))); }

Expr Expr::operator*(const Expr& rhs) const { return Expr(Handle(new Term('*' , h , rhs.h))); }

Expr Expr::operator/(const Expr& rhs) const { return Expr(Handle(new Term('/' , h , rhs.h))); }