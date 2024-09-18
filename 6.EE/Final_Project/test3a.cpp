/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c value.cpp
    $ g++ -c symbol.cpp
    $ g++ -c handle.cpp
    $ g++ -g test3a.cpp -o test3a base.o value.o symbol.o handle.o
    $ valgrind ./test3a (or $ ./test3a)
*/

#include <iostream>
#include "symbol.h"
#include "value.h"
#include "handle.h"
using namespace std;

int main() {

    Handle h1(new Symbol('a'));
    Handle h2(new Value(3.14));

    // Test print function
    cout << "Handle h1: "; h1.print(cout); cout << endl;
    cout << "Handle h2: "; h2.print(cout); cout << endl;
    cout << endl;

    // Test eval function
    cout << "Eval h1: " << h1.eval() << endl;
    cout << "Eval h2: " << h2.eval() << endl;
    cout << endl;

    // Test type function (reference: base.h)
    cout << "Type h1: " << (h1.type() == 0 ? "VALUE" : "SYMBOL") << endl;
    cout << "Type h2: " << (h2.type() == 0 ? "VALUE" : "SYMBOL") << endl;
    cout << endl;
       
    return 0;
}
