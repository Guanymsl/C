/*
    Command to compile:
    $ g++ -c bonus.cpp
    $ g++ -g test8d.cpp -o test8d bonus.o
    $ valgrind ./test8d (or $ ./test8d)
*/

#include <iostream>
#include "bonus.h"
using namespace std;

void printUse(const char * name, const Expr& e)
{
    cout << name << ".h.p->use = " << e.h.p->use << endl;
}

int main()
{
    Expr n('n'), t('t'), u('u'), e('e');
    Expr ntu = n*t*u;
    Expr ee = e+e;
    Expr ntuee = ntu + ee;
    
    cout << "(1) ntu = " << ntu << endl;
    cout << "(2) ee = " << ee << endl;
    cout << "(3) ntuee = " << ntuee << endl;
    printUse("(4) t", t);

    ntuee.subst('n', ntu);
		cout << "After ntuee.subst('n', ntu):" << endl;
    cout << "(5) ntu = " << ntu << endl;
    cout << "(6) ntuee = " << ntuee << endl;
    printUse("(7) t", t);

    
    return 0;
}