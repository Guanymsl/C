/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c value.cpp
    $ g++ -c symbol.cpp
    $ g++ -c handle.cpp
    $ g++ -c term.cpp
    $ g++ -c expr.cpp
    $ g++ -g test5b.cpp -o test5b base.o value.o symbol.o handle.o term.o expr.o
    $ valgrind ./test5b (or $ ./test5b)
*/

#include "expr.h"
#include <iostream>
using namespace std;

int main()
{
    Expr n('n'), t('t'), u('u'), e('e');
    Expr zero(0.0), one(1.0), four(4.0);
    Expr zero2(zero);
    Expr res = one*four*zero2+four+one+one ;
    cout << "res.eval()=" << res.eval() << endl;
    cout << (n+t+u+e+e)*(one+zero+zero2+four) << endl;

    return 0;
}