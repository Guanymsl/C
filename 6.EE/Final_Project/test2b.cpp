/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c symbol.cpp
    $ g++ -g test2b.cpp -o test2b base.o symbol.o
    $ valgrind ./test2b (or $ ./test2b)
*/


#include <iostream>
#include "base.h"
#include "symbol.h"
using namespace std;

int main()
{
    Base *s1 = new Symbol('y'), *s2 = new Symbol('m'), *s3 = new Symbol('x'), *s4 = new Symbol('b');
    s1->print(cout); cout << "="; s2->print(cout); cout << "*"; s3->print(cout); cout << "+"; s4->print(cout); cout << endl;
    cout << "s1->type=" << (s1->type == SYMBOL ? "SYMBOL" : "ERROR") << endl;
    cout << "s2->type=" << (s2->type == SYMBOL ? "SYMBOL" : "ERROR") << endl;
    cout << "s3->type=" << (s3->type == SYMBOL ? "SYMBOL" : "ERROR") << endl;
    cout << "s4->type=" << (s4->type == SYMBOL ? "SYMBOL" : "ERROR") << endl;

    cout << s4->eval() << endl;

    delete s1;
    delete s2;
    delete s3;
    delete s4;

    return 0;
}