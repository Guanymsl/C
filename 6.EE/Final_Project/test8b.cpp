/*
    Command to compile:
    $ g++ -c bonus.cpp
    $ g++ -g test8b.cpp -o test8b bonus.o
    $ valgrind ./test8b (or $ ./test8b)
*/

#include <iostream>
#include "bonus.h"
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