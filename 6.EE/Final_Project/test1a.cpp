/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c value.cpp
    $ g++ -g test1a.cpp -o test1a base.o value.o
    $ valgrind ./test1a (or $ ./test1a)
*/


#include <iostream>
#include "base.h"
#include "value.h"
using namespace std;

int main()
{
    Base *m = new Value(2.5), *a = new Value(9.8);
    cout << "*m="; m->print(cout); cout << endl;
    cout << "m->type=" << (m->type == VALUE ? "VALUE" : "ERROR") << endl;
    cout << "*a="; a->print(cout); cout << endl;
    cout << "a->type=" << (a->type == VALUE ? "VALUE" : "ERROR") << endl;
    cout << "f=m*a=" << m->eval() * a->eval() << endl;

    delete m;
    delete a;

    return 0;
}