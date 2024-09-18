/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c value.cpp
    $ g++ -c symbol.cpp
    $ g++ -c handle.cpp
    $ g++ -c term.cpp
    $ g++ -g test4b.cpp -o test4b base.o value.o symbol.o handle.o term.o
    $ valgrind ./test4b (or $ ./test4b)
*/

#include "value.h"
#include "symbol.h"
#include "handle.h"
#include "term.h"
#include <iostream>
using namespace std;


int main()
{
    Handle h1(new Value(12.4)), h2(new Value(7.6)), h3(new Symbol('t')), h4(new Value(9.8));
    Handle term1(new Term('+', h1, h2));
    cout << "term1="; term1.print(cout); cout << " = " << term1.eval() << endl;

    Handle term2(new Term('+', h3, h3));
    cout << "term2="; term2.print(cout); cout << endl;

    Handle term3(new Term('*', term1, term2));
    cout << "term3="; term3.print(cout); cout << " = " << term1.eval() << "*"; term2.print(cout); cout << endl;

    Handle term4(new Term('*', term2, term2));
    cout << "term4="; term4.print(cout); cout << endl;

    Handle term5(new Term('*', h4, term4));
    cout << "term5="; term5.print(cout); cout << endl;

    Handle term6(new Term('+', term3, term5));
    cout << "term6="; term6.print(cout); cout << " = " << term1.eval() << "*";
    term2.print(cout); cout << "+"; term5.print(cout); cout << endl;

    

    return 0;
}