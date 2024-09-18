/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c symbol.cpp
    $ g++ -g test2a.cpp -o test2a base.o symbol.o
    $ valgrind ./test2a (or $ ./test2a)
*/


#include <iostream>
#include "base.h"
#include "symbol.h"
using namespace std;

int main()
{
    Base *s1 = new Symbol('f'), *s2 = new Symbol('m'), *s3 = new Symbol('a');
    s1->print(cout); cout << "="; s2->print(cout); cout << "*"; s3->print(cout); cout << endl;
    cout << "s1->type=" << (s1->type == SYMBOL ? "SYMBOL" : "ERROR") << endl;
    cout << "s2->type=" << (s2->type == SYMBOL ? "SYMBOL" : "ERROR") << endl;
    cout << "s3->type=" << (s3->type == SYMBOL ? "SYMBOL" : "ERROR") << endl;

    delete s1;
    delete s2;
    delete s3;

    return 0;
}