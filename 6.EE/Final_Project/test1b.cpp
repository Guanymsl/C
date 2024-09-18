/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c value.cpp
    $ g++ -g test1b.cpp -o test1b base.o value.o
    $ valgrind ./test1b (or $ ./test1b)
*/

#include <iostream>
#include "base.h"
#include "value.h"
using namespace std;

int main()
{
    Base *m = new Value(3.2), *x = new Value(4.0), *b = new Value(5.4);
    cout << "*m="; m->print(cout); cout << endl;
    cout << "m->type=" << (m->type == VALUE ? "VALUE" : "ERROR") << endl;
    cout << "*x="; x->print(cout); cout << endl;
    cout << "x->type=" << (x->type == VALUE ? "VALUE" : "ERROR") << endl;
    cout << "*b="; b->print(cout); cout << endl;
    cout << "b->type=" << (b->type == VALUE ? "VALUE" : "ERROR") << endl;
    cout << "y=m*x+b=" << m->eval() * x->eval() + b->eval() << endl;

    delete m;
    delete x;
    delete b;

    return 0;
}