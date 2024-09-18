/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c symbol.cpp
    $ g++ -c value.cpp
    $ g++ -c term.cpp
    $ g++ -c expr.cpp
    $ g++ -c handle.cpp
    $ g++ -g test6b.cpp -o test6b base.o symbol.o value.o term.o handle.o
    $ valgrind ./test6b (or $ ./test6b)
*/

#include <iostream>
#include "symbol.h"
#include "value.h"
#include "term.h"
#include "handle.h"
using namespace std;

int main()
{
	// Test: subst(char, const Handle&)
    Handle h4(new Symbol('p'));
    Handle h5(new Value(2.0));
    Handle h6(new Symbol('q'));
    Term t2('*', h4, h5);

    cout << "Test: substitute char with Symbol via Handle" << endl;
    cout << "t2 = "; t2.print(cout); cout << endl;

    cout << "\nSubstitute p with q" << endl;
    t2.subst('p', h6);
    cout << "t2 = "; t2.print(cout); cout << endl;

    return 0;
}
