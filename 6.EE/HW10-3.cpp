//*** Don't submit the code segment below.
#include <iostream>
#include <algorithm>
using namespace std;

class Linked_List {
public:
	Linked_List(int);
	void insert(Linked_List *);
	void out();
	int getVal() const;
	Linked_List *prev, *next;
private:
	int val;
};

//Linked_List::Linked_List(int _val) : val(_val), prev(this), next(this) {}


int Linked_List::getVal() const
{
	return val;
}

ostream& operator<< (ostream& o, const Linked_List &l)
{
	const Linked_List *head = &l;
	const Linked_List *ptr = head;
	do
	{
		o << ptr->getVal() << "<->";
		ptr = ptr->next;
	} while (ptr != head);
	o << ptr->getVal();
	return o;
}

void reversell();

//*** Don't submit the code segment above.

void Linked_List::insert(Linked_List *node)
{

    node->next = next;
    node->prev = this;
    next->prev = node;
    next = node;

}

void Linked_List::out()
{

    next->prev = prev;
    prev->next = next;

}

void reversell(Linked_List *ptr)
{

    Linked_List *cur = ptr->next;

    int cnt = 0;

    while(cur != ptr){

        cur = cur->next;
        cnt++;

    }
    cnt++;

    //cout << "cnt = " << cnt << '\n';

	while(cnt--){

        swap(cur->next , cur->prev);

        cur = cur->prev;

    }

}

//*** Don't submit the code segment below.

Linked_List *walking(Linked_List *ptr, int walk)
{
	if (walk < 0)
	{
		walk = -walk;
		for (int j = 0; j < walk; ++j)
		{
			ptr = ptr->prev;
		}
	}
	else
	{
		for (int j = 0; j < walk; ++j)
		{
			ptr = ptr->next;
		}
	}
	return ptr;
}

int main()
{
	Linked_List *head = new Linked_List(1);
	Linked_List *ptr = head;
	int tcas;
	cin >> tcas;
	for(int i = 0; i < tcas; ++i)
	{
		Linked_List *node = nullptr;
		int op;
		cin >> op;
		if (op == 0)
		{
			int val;
			cin >> val;
			ptr->insert(new Linked_List(val));
		}
		else if (op == 1)
		{
			node = ptr;
			ptr = ptr->next;
			node->out();
			delete node;
		}
		else if (op == 2)
		{
			reversell(ptr);
		}
		else if (op == 3)
		{
			int walk;
			cin >> walk;
			ptr = walking(ptr, walk);
		}
		else if (op == 4)
		{
			cout << *ptr << endl;
		}
	}
	return 0;
}
//*** Don't submit the code segment above.