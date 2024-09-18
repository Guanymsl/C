/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c value.cpp
    $ g++ -c symbol.cpp
    $ g++ -c handle.cpp
    $ g++ -c term.cpp
    $ g++ -c expr.cpp
    $ g++ -g test7a.cpp -o test7a base.o value.o symbol.o handle.o term.o expr.o
    $ valgrind ./test7a (or $ ./test7a)
*/

#include <iostream>
#include "expr.h"
using namespace std;

int main()
{
	Expr a('a'), b('b'), c('c'), d('d'), one(1.0);
	Expr x = ((a + b) + b);
	Expr y = x;
	Expr z = ((c + d) + one);
	cout << "(1) x = " << x << endl;
	cout << "(2) y = " << y << endl;
	cout << "(3) z = " << z << endl;
	x.subst('b', z);
	cout << "(4) x = " << x << endl;
	cout << "(5) y = " << y << endl;
	return 0;
}