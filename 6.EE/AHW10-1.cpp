//*** Don't submit the code segment below.
#include<iostream>
#include<cstring>
using namespace std;

class String {
friend ostream& operator << (ostream& o, const String& s);
public:
	// Constructors
	String();
	String(const char *);
	String(const String &);

	// Operators
	String& operator = (const String &);
	String& operator = (const char *);
	String operator + (const char *);
	String operator + (const String &);
	String& operator += (const char *);
	String& operator += (const String &);

	bool operator == (const String &) const;
	bool operator == (const char *) const;
	bool operator != (const String &) const;
	bool operator != (const char *) const;

	// Functions
	char& operator [] (int);
	int length() const;

	// After class part.
	~String();
	void push_back(char);
	String substr(int, int);

private:
	int len; // The length if the C-string in s.
	int cap; // The capacity (real length) of the array s.
	char *s; // C-string
};


ostream& operator << (ostream& o, const String& str)
{
	o << str.s;
	return o;
}
//*** Don't submit the code segment above.

String::String(){

	s = new char[1];
    s[0] = '\0';
	len = 0;
	cap = 1;

}

String::String(const char *rhs){

	int ind = 0;
	while(rhs[ind] != '\0') ind++;

	len = ind;
	cap = len + 1;
	s = new char[cap];
	for(int i=0; i<=len; i++) s[i] = rhs[i];

}

String::String(const String& rhs){

	len = rhs.len;
	cap = len + 1;
	s = new char[cap];
	for(int i=0; i<=rhs.len; i++) s[i] = rhs.s[i];

}

String& String::operator = (const String &rhs){

	delete []s;
	s = new char[rhs.len + 1];
	len = rhs.len;
	cap = len + 1;

	for(int i=0; i<=rhs.len; i++) s[i] = rhs.s[i];

	return *this;

}

String& String::operator = (const char *rhs){

	String temp(rhs);

	delete []s;
	s = new char[temp.len + 1];
	len = temp.len;
	cap = len + 1;

	for(int i=0; i<=temp.len; i++) s[i] = temp.s[i];

	return *this;

}

String String::operator + (const char *rhs){

	String temp(rhs);

	char *lhs = new char[len + temp.len + 1];

	for(int i=0; i<len; i++) lhs[i] = s[i];
	for(int i=0; i<=temp.len; i++) lhs[len + i] = temp.s[i];

	String ans(lhs);
    delete []lhs;
	return ans;

}

String String::operator + (const String &rhs){

	char *lhs = new char[len + rhs.len + 1];

	for(int i=0; i<len; i++) lhs[i] = s[i];
	for(int i=0; i<=rhs.len; i++) lhs[len + i] = rhs.s[i];

	String ans(lhs);
	delete []lhs;
	return ans;

}

String& String::operator += (const char *rhs){

	String temp(rhs);

	if(len + temp.len + 1 > cap){

		do{

			cap = 2 * cap;

		}while(len + temp.len + 1 > cap);

		char *lhs = new char[cap];

		for(int i=0; i<len; i++) lhs[i] = s[i];
		for(int i=0; i<temp.len; i++) lhs[len + i] = temp.s[i];
		lhs[len + temp.len] = '\0';

		String ans(lhs);
		*this = ans;
		delete[]lhs;

	}else for(int i=0; i<=temp.len; i++) s[len + i] = temp.s[i] , len += temp.len;

	return *this;

}

String& String::operator += (const String &rhs){

	if(len + rhs.len + 1 > cap){

		do{

			cap = 2 * cap;

		}while(len + rhs.len + 1 > cap);

		char *lhs = new char[cap];

		for(int i=0; i<len; i++) lhs[i] = s[i];
		for(int i=0; i<=rhs.len; i++) lhs[len + i] = rhs.s[i];

		String ans(lhs);
		*this = ans;
		delete[]lhs;

	}else for(int i=0; i<=rhs.len; i++) s[len + i] = rhs.s[i] , len += rhs.len;

	return *this;

}

bool String::operator == (const String &rhs) const{

	if(len != rhs.len) return false;
	for(int i=0; i<len; i++) if(s[i] != rhs.s[i]) return false;

	return true;

}

bool String::operator == (const char *rhs) const{

	String temp(rhs);

	if(len != temp.len) return false;
	for(int i=0; i<len; i++) if(s[i] != temp.s[i]) return false;

	return true;

}

bool String::operator != (const String &rhs) const{ return !(s == rhs.s); }

bool String::operator != (const char *rhs) const{

	String temp(rhs);
	return !(s == temp.s);

}

char &String::operator [](const int idx){ return s[idx]; }

int String::length() const {

	int l = 0;
	while(s[l] != '\0') l++;

	return l;

}

// After class part

String::~String(){ delete []s; }

void String::push_back(char _c){

	if(len + 2 > cap){

		char *temp = new char[cap];
		for(int i=0; i<len; i++) temp[i] = s[i];

		cap = 2 * cap;
		delete []s;
		s = new char[cap];

		for(int i=0; i<len; i++) s[i] = temp[i];
		s[len] = _c;
		s[++len] = '\0';

		delete []temp;

	}else{

		s[len] = _c;
		s[++len] = '\0';

	}

}

String String::substr(int _pos, int _len){

	char *temp = new char[_len + 1];
	for(int i=0; i<_len; i++) temp[i] = s[_pos + i];
	temp[_len] = '\0';

	String ans(temp);
	delete []temp;
	return ans;

}

//*** Don't submit the code segment below.
int main()
{
	int op;
	cin >> op;
	if (op == 0)
	{
		String a = "ntuee", b("1004");
		String c = a, d = a + b;
		String e(a);
		String f; // empty string
		e[0] = 'x';
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "c = " << c << endl;
		cout << "d = " << d << endl;
		cout << "e = " << e << endl;
		cout << "f.length() = " << f.length() << endl;
		if (d == a + b)
		{
			cout << d << " is equal to " << a + b << "." << endl;
		}
		if (d == "ntuee1004")
		{
			cout << d << " is equal to " << "ntuee1004" << "." << endl;
		}
		c[0] = 't';
		if (c != a)
		{
			cout << c << String(" is not equal to ") << a << "." << endl;
		}
		if (c != "ntuee")
		{
			cout << c << " is not equal to " << "ntuee" << "." << endl;
		}
		if (d != "ntuee10045")
		{
			cout << d << " is not equal to " << "ntuee10045" << "." << endl;
		}
		b += "cprog";
		cout << "b = " << b << endl;
		a += b + "haha" + c + b;
		cout << "a = " << a << endl;
		cout << "a.length() = " << a.length() << endl;
		cout << a + b + c + d + d + a + b + b + "..." << endl;

		String pb;
		for (int i = 0; i < 100000; ++i)
		{
			pb.push_back('Z');
		}
		cout << "pb.length = " << pb.length() << endl;
		pb = pb.substr(3, 50);
		cout << "pb = " << pb << endl;
	}
	else if (op == 1)
	{
		// Some hidden operations like op is 0.
	}
	return 0;
}
//*** Don't submit the code segment above.