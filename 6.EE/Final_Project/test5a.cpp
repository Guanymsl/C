/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c value.cpp
    $ g++ -c symbol.cpp
    $ g++ -c handle.cpp
    $ g++ -c term.cpp
    $ g++ -c expr.cpp
    $ g++ -g test5a.cpp -o test5a base.o value.o symbol.o handle.o term.o expr.o
    $ valgrind ./test5a (or $ ./test5a)
*/

#include "expr.h"
#include <iostream>
using namespace std;

int main()
{
    Expr x('f'), y('m'), z('a');
    Expr t(1.0), u(2.0);
    Expr v(u);
    Expr res = t + v;
    cout << "res.eval()=" << res.eval() << endl;
    cout << x << "=" << (y+t+u)*(z+v) << endl;

    return 0;
}