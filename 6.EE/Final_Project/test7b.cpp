/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c value.cpp
    $ g++ -c symbol.cpp
    $ g++ -c handle.cpp
    $ g++ -c term.cpp
    $ g++ -c expr.cpp
    $ g++ -g test7b.cpp -o test7b base.o value.o symbol.o handle.o term.o expr.o
    $ valgrind ./test7b (or $ ./test7b)
*/

#include <iostream>
#include "expr.h"
using namespace std;

int main()
{
    Expr n('n'), t('t'), u('u'), e('e');
    Expr ntu = n*t*u;
    Expr ee = e+e;
    Expr ntuee = ntu + ee;

    cout << "(1) ntu = " << ntu << endl;
    cout << "(2) ee = " << ee << endl;
    cout << "(3) ntuee = " << ntuee << endl;

    ntuee.subst('n', ee);
	cout << "After ntuee.subst('n', ee):" << endl;
    cout << "(4) ntu = " << ntu << endl;
    cout << "(5) ntuee = " << ntuee << endl;
    return 0;
}