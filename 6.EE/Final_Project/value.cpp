#include "value.h"
#include "base.h"

Value::Value(double _val) { val = _val , type = VALUE; }

void Value::print(ostream& o) const { o << val; }

double Value::eval() const { return val; }

void Value::subst(char c , const Handle& rhs){ return; }