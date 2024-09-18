#include <deque>
#include <iostream>

using namespace std;

class Linked_List {
  public:

    deque<int> dq;

    void prepend(int x){

        dq.push_back(x);

    }

    void append(int x){

        dq.push_front(x);

    }

    void reverse(){
        return;
    }


};

ostream& operator<<(ostream& o, Linked_List& ll) {

	for (deque<int>::iterator it = ll.dq.begin(); it != ll.dq.end(); it++)
		o << *it << "->";
	o << "NULL";

	return o;

}