/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c symbol.cpp
    $ g++ -c value.cpp
    $ g++ -c term.cpp
    $ g++ -c expr.cpp
    $ g++ -c handle.cpp
    $ g++ -g test6a.cpp -o test6a base.o symbol.o value.o term.o handle.o
    $ valgrind ./test6a (or $ ./test6a)
*/

#include <iostream>
#include "symbol.h"
#include "value.h"
#include "term.h"
#include "handle.h"
using namespace std;

int main() {
    // Test: subst(char, const Handle&)
    Handle h1(new Value(1.0));
    Handle h2(new Symbol('x'));
    Handle h3(new Value(-5.0));
    Term t1('+', h1, h2);

    cout << "Test: substitute char with Value via Handle" << endl;
    cout << "t1 = "; t1.print(cout); cout << endl;
    
    cout << "Substitute x with -5.0" << endl;
    t1.subst('x', h3);
    cout << "t1 = "; t1.print(cout); 
    cout << " = " << t1.eval() << endl;

    return 0;
}
