/*
    Command to compile:
    $ g++ -c bonus.cpp
    $ g++ -g test8a.cpp -o test8a bonus.o
    $ valgrind ./test8a (or $ ./test8a)
*/

#include <iostream>
#include "bonus.h"
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