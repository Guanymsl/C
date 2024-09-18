/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c value.cpp
    $ g++ -c symbol.cpp
    $ g++ -c handle.cpp
    $ g++ -c term.cpp
    $ g++ -g test4a.cpp -o test4a base.o value.o symbol.o handle.o term.o
    $ valgrind ./test4a (or $ ./test4a)
*/

#include "value.h"
#include "symbol.h"
#include "handle.h"
#include "term.h"
#include <iostream>
using namespace std;

int main()
{
    Handle h1(new Symbol('x')), h2(new Symbol('y'));
    Handle h3(new Value(1.0)), h4(new Value(3.0)), h5(new Value(4.0));

    Handle t1(new Term('+', h1, h2));
    cout << "t1=";  t1.print(cout); cout << endl;


    Handle t2(new Term('+', h1, h3));
    cout << "t2="; t2.print(cout); cout << endl;


    Handle t3(new Term('+', h3, h5));
    cout << "t3="; t3.print(cout); cout << " = " << t3.eval() << endl;


    Handle t4(new Term('*', t1, t2));
    cout << "t4="; t4.print(cout); cout << endl;


    Handle t5(new Term('+', t4, t3));
    cout << "t5="; t5.print(cout); cout << endl;


    return 0;
}