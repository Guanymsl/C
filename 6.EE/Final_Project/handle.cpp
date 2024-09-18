#include "handle.h"
#include "base.h"
#include "symbol.h"

Handle::Handle() { p = nullptr; }

Handle::Handle(Base *_p) { p = _p; }

Handle::Handle(const Handle& rhs) {

    p = rhs.p;
    p->use++;

}

Handle::~Handle() { if(p != nullptr && --(p->use) == 0) delete p; }

Handle& Handle::operator=(const Handle& rhs) {

    if(p != nullptr){

        if(p->use == 1) delete p;
        else p->use--;

    }

    p = rhs.p;
    p->use++;

    return *this;

}

void Handle::print(ostream& o) const { p->print(o); }

double Handle::eval() const { return p->eval(); }

TYPE Handle::type() const { return p->type; }

void Handle::subst(char c , const Handle& rhs) {

    if(p->type == SYMBOL && dynamic_cast<Symbol*>(p)->sym == c) *this = rhs;
    if(p->type == TERM) p->subst(c , rhs);

}