/*
    Command to compile:
    $ g++ -c bonus.cpp
    $ g++ -g test8c.cpp -o test8c bonus.o
    $ valgrind ./test8c (or $ ./test8c)
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
    Expr n('n'), t('t'), u('u');
    Expr ntu = n*t*u;
    Expr e('e');
    Expr u2 = u;

    cout << "(1) ntu = " << ntu << endl;
    cout << "(2) e = " << e << endl;
    
    printUse("(3) ntu", ntu);
    printUse("(4) n", n);
    printUse("(5) t", t);
    printUse("(6) u", u);
    printUse("(7) e", e);

    u.subst('u', e);
    cout << "After u.subst('u', e):" << endl;
    cout << "(8) ntu = " << ntu << endl;
    cout << "(9) u = " << u << endl;
    printUse("(10) u", u);
    printUse("(11) u2", u2);
    printUse("(12) e", e);

    ntu.subst('n', e);
		cout << "After ntu.subst('n', e):" << endl;
    cout << "(13) ntu = " << ntu << endl;
    printUse("(14) n", n);
    printUse("(15) e", e);
    

    return 0;
}