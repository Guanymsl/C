/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c symbol.cpp
    $ g++ -c value.cpp
    $ g++ -c term.cpp
    $ g++ -c expr.cpp
    $ g++ -c handle.cpp
    $ g++ -g test6c.cpp -o test6c base.o symbol.o value.o term.o handle.o
    $ valgrind ./test6c (or $ ./test6c)
*/

#include <iostream>
#include "symbol.h"
#include "value.h"
#include "term.h"
#include "handle.h"
using namespace std;

int main() {
    // Test: subst(char, const Handle&)
    Handle h7(new Symbol('a'));
    Handle h8(new Value(1004));
    Handle h9(new Symbol('b'));
    Term t3('+', h7, h8);
    Handle h10(new Term('*', h7, h9));

    cout << "Test: substitute char with Term via Handle" << endl;
    cout << "t3 = "; t3.print(cout); cout << endl;
    cout << "Term in h10 = "; h10.p->print(cout); cout << endl;

    cout << "\nSubstitute a with t4" << endl;
    t3.subst('a', h10);
    cout << "t3 = "; t3.print(cout); cout << endl;

    return 0;
}