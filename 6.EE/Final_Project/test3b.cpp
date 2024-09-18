/*
    Command to compile:
    $ g++ -c base.cpp
    $ g++ -c value.cpp
    $ g++ -c symbol.cpp
    $ g++ -c handle.cpp
    $ g++ -g test3b.cpp -o test3b base.o value.o symbol.o handle.o
    $ valgrind ./test3b (or $ ./test3b)
*/


#include <iostream>
#include "symbol.h"
#include "value.h"
#include "handle.h"
using namespace std;

int main() {

    Handle h1(new Symbol('x'));
    Handle h2(new Value(2.94));

    // Test copy constructor
    Handle h3(h1);
    cout << "Copy h1 to h3" << endl;
    cout << "Handle h3: "; h3.print(cout); cout << endl;
    cout << "Eval h3: " << h3.eval() << endl;
    cout << "Type h3: " << (h3.type() == 0 ? "VALUE" : "SYMBOL") << endl;
    cout << endl;

    // Test copy assignment operator
    h3 = h2;
    cout << "Copy h2 to h3" << endl;
    cout << "Handle h3: "; h3.print(cout); cout << endl;
    cout << "Eval h3: " << h3.eval() << endl;
    cout << "Type h3: " << (h3.type() == 0 ? "VALUE" : "SYMBOL") << endl;
    cout << endl;
       
    return 0;
}
