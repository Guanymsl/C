#include "symbol.h"
#include "base.h"

Symbol::Symbol(char _sym) { sym = _sym , type = SYMBOL; }

void Symbol::print(ostream& o) const { o << sym; }

double Symbol::eval() const {

    cout << sym << " is not defined.\n";
    return 0;

}

void Symbol::subst(char c , const Handle& rhs){ return; }