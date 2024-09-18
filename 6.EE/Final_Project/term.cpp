#include "term.h"
#include "symbol.h"
#include "base.h"

Term::Term(char _op , Handle _left , Handle _right) {

    op = _op;
    left = _left;
    right = _right;
    type = TERM;

}

void Term::print(ostream& o) const {

    o << "(";
    if(left.p->type == TERM) left.print(o);

    if(left.p->type == VALUE) o << left.eval();
    else if(left.p->type == SYMBOL) o << (dynamic_cast<Symbol*>(left.p))->sym;

    o << op;

    if(right.p->type == TERM) right.print(o);

    if(right.p->type == VALUE) o << right.eval();
    else if(right.p->type == SYMBOL) o << (dynamic_cast<Symbol*>(right.p))->sym;

    o << ")";

}

double Term::eval() const {

    if(op == '+') return left.eval() + right.eval();
    if(op == '-') return left.eval() - right.eval();
    if(op == '*') return left.eval() * right.eval();
    return left.eval() / right.eval();

}

void Term::subst(char c , const Handle& rhs) {

    if(left.p->type == TERM) left.subst(c , rhs);
    if(left.p->type == SYMBOL && dynamic_cast<Symbol*>(left.p)->sym == c) left = rhs;

    if(right.p->type == TERM) right.subst(c , rhs);
    if(right.p->type == SYMBOL && dynamic_cast<Symbol*>(right.p)->sym == c) right = rhs;

}