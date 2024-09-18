#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//############################# Do not modify the code below #############################//
//==== base.h =========
class Base {
	friend class Handle;
public:
	virtual ~Base();
	virtual void print(ostream& o) const = 0;
	virtual char* type() const = 0;
	virtual Base* clone() const = 0;
};

//==== base.cpp =======
Base::~Base() {}

//==== double.h =======
class Double: public Base {
	friend class Handle;
public:
	Double(double _val);
	void print(ostream& o) const;
	char* type() const;
	Base* clone() const;
protected:
	double val;
};

//==== complex.h =======
class Complex: public Base {
	friend class Handle;
public:
	Complex(double _real, double _imag);
	void print(ostream& o) const;
	char* type() const;
	Base* clone() const;
protected:
	double real;
	double imag;
};

//############################# Do not modify the code above #############################//


//############################# Modify the code below #############################//

//==== double.cpp ======
Double::Double(double _val){
	val = _val;
}
void Double::print(ostream& o) const {
	o << fixed << setprecision(2) << val;
}
char* Double::type() const {
	return (char*)"<type 'double'>";
}
Base* Double::clone() const {
	Base *p = new Double(val);
	return p;
}

//==== complex.cpp ======
Complex::Complex(double _real, double _imag) {
	real = _real;
	imag = _imag;
}
void Complex::print(ostream& o) const {
	if(imag < 0) o << fixed << setprecision(2) << real << " - " << -imag << "j";
	else o << fixed << setprecision(2) << real << " + " << imag << "j";
}
char* Complex::type() const {
	return (char*)"<type 'complex'>";
}
Base* Complex::clone() const {
	Base *p = new Complex(real , imag);
	return p;
}


//==== handle.h =======
class Handle {
friend ostream& operator<< (ostream& o, const Handle& h);

public:
	// Constructors and destructor
	Handle();
	Handle(double _val);
	Handle(double _real, double _imag);
	Handle(const Handle& h);
	~Handle();

	char* type() const { return p->type(); }

	// Operator overloading
	Handle& operator= (const Handle& h);
	Handle& operator+= (const Handle& h);
	Handle operator+ (const Handle& h);
	Handle& operator-= (const Handle& h);
	Handle operator- (const Handle& h);
	Handle& operator*= (const Handle& h);
	Handle operator* (const Handle& h);
	Handle& operator/= (const Handle& h);
	Handle operator/ (const Handle& h);

protected:
	Base *p;
};

//==== handle.cpp =====
Handle::Handle() {
	p = nullptr;
}
Handle::Handle(double _val) {
	p = new Double(_val);
}
Handle::Handle(double _real, double _imag) {
	p = new Complex(_real , _imag);
}
Handle::Handle(const Handle& h) {
	p = h.p->clone();
}
Handle::~Handle() {
	delete p;
}
Handle& Handle::operator= (const Handle& h) {
	p = h.p->clone();
	return *this;
}
Handle& Handle::operator+= (const Handle& h) {

	if(p->type() == h.p->type()){

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Double(d->val + hd->val);
			p = temp;
			return *this;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			Base *temp = new Complex(d->real + hd->real , d->imag + hd->imag);
			p = temp;
			return *this;

		}

	}else{

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			Base *temp = new Complex(d->val + hd->real , hd->imag);
			p = temp;
			return *this;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Complex(d->real + hd->val , d->imag);
			p = temp;
			return *this;

		}

	}

}
Handle Handle::operator+ (const Handle& h) {

	if(p->type() == h.p->type()){

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Double(d->val + hd->val);
			Handle ans;
			ans.p = temp;
			return ans;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			Base *temp = new Complex(d->real + hd->real , d->imag + hd->imag);
			Handle ans;
			ans.p = temp;
			return ans;

		}

	}else{

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			Base *temp = new Complex(d->val + hd->real , hd->imag);
			Handle ans;
			ans.p = temp;
			return ans;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Complex(d->real + hd->val , d->imag);
			Handle ans;
			ans.p = temp;
			return ans;

		}

	}

}
Handle& Handle::operator-= (const Handle& h) {

	if(p->type() == h.p->type()){

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Double(d->val - hd->val);
			p = temp;
			return *this;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			Base *temp = new Complex(d->real - hd->real , d->imag - hd->imag);
			p = temp;
			return *this;
		}

	}else{

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			Base *temp = new Complex(d->val - hd->real , -hd->imag);
			p = temp;
			return *this;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Complex(d->real - hd->val , d->imag);
			p = temp;
			return *this;

		}

	}

}
Handle Handle::operator- (const Handle& h) {

	if(p->type() == h.p->type()){

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Double(d->val - hd->val);
			Handle ans;
			ans.p = temp;
			return ans;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			Base *temp = new Complex(d->real - hd->real , d->imag - hd->imag);
			Handle ans;
			ans.p = temp;
			return ans;

		}

	}else{

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			Base *temp = new Complex(d->val - hd->real , -hd->imag);
			Handle ans;
			ans.p = temp;
			return ans;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Complex(d->real - hd->val , d->imag);
			Handle ans;
			ans.p = temp;
			return ans;

		}

	}

}
Handle& Handle::operator*= (const Handle& h) {

	if(p->type() == h.p->type()){

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Double(d->val * hd->val);
			p = temp;
			return *this;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			double A = d->real , B = d->imag , C = hd->real , D = hd->imag;
			Base *temp = new Complex(A * C - B * D , B * C + A * D);
			p = temp;
			return *this;

		}

	}else{

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			Base *temp = new Complex(d->val * hd->real , d->val * hd->imag);
			p = temp;
			return *this;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Complex(d->real * hd->val , d->imag * hd->val);
			p = temp;
			return *this;

		}

	}

}
Handle Handle::operator* (const Handle& h) {

	if(p->type() == h.p->type()){

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Double(d->val * hd->val);
			Handle ans;
			ans.p = temp;
			return ans;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			double A = d->real , B = d->imag , C = hd->real , D = hd->imag;
			Base *temp = new Complex(A * C - B * D , B * C + A * D);
			Handle ans;
			ans.p = temp;
			return ans;

		}

	}else{

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			Base *temp = new Complex(d->val * hd->real , d->val * hd->imag);
			Handle ans;
			ans.p = temp;
			return ans;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Complex(d->real * hd->val , d->imag * hd->val);
			Handle ans;
			ans.p = temp;
			return ans;

		}

	}

}
Handle& Handle::operator/= (const Handle& h) {

	if(p->type() == h.p->type()){

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Double(d->val / hd->val);
			p = temp;
			return *this;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			double A = d->real , B = d->imag , C = hd->real , D = hd->imag , N = C * C + D * D;
			Base *temp = new Complex((A * C + B * D) / N , (B * C - A * D) / N);
			p = temp;
			return *this;

		}

	}else{

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			Base *temp = new Complex(d->val / hd->real , d->val / hd->imag);
			p = temp;
			return *this;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Complex(d->real / hd->val , d->imag / hd->val);
			p = temp;
			return *this;

		}

	}

}
Handle Handle::operator/ (const Handle& h) {

	if(p->type() == h.p->type()){

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Double(d->val / hd->val);
			Handle ans;
			ans.p = temp;
			return ans;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			double A = d->real , B = d->imag , C = hd->real , D = hd->imag , N = C * C + D * D;
			Base *temp = new Complex((A * C + B * D) / N , (B * C - A * D) / N);
			Handle ans;
			ans.p = temp;
			return ans;

		}

	}else{

		if((p->type())[7] == 'd'){

			Double *d = dynamic_cast<Double*>(p);
			Complex *hd = dynamic_cast<Complex*>(h.p);
			Base *temp = new Complex(d->val / hd->real , d->val / hd->imag);
			Handle ans;
			ans.p = temp;
			return ans;

		}else{

			Complex *d = dynamic_cast<Complex*>(p);
			Double *hd = dynamic_cast<Double*>(h.p);
			Base *temp = new Complex(d->real / hd->val , d->imag / hd->val);
			Handle ans;
			ans.p = temp;
			return ans;

		}

	}

}

//==== friend function =====
ostream& operator<< (ostream& o, const Handle& h) {
	h.p->print(o);
	return o;
}

//############################# Modify the code above #############################//


//############################# Do not modify the code below #############################//

void Sample1(){
	/*
		Goal:
			- Print the types and values
	*/

	double double_;
	double real_, imag_;

	// cout << "Enter a double for d:\n";
	cin >> double_;
	// cout << "Enter a complex number (real imag) for c:\n";
	cin >> real_ >> imag_;

	Handle d(double_);
	Handle c(real_, imag_);

	cout << "Type of d: " << d.type() << endl;
	cout << "d = " << d << endl;

	cout << "Type of c: " << c.type() << endl;
	cout << "c = " << c << endl;

	return;
}

void Sample2(){
	/*
		Goal:
			- Test the constructors and the copier
	*/
	double double_1;
	double real_1, imag_1;

	// cout << "Enter a double for d1:\n";
	cin >> double_1;

	Handle d1(double_1);
	Handle d2(d1);
	Handle d3 = d1;

	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;
	cout << "d3 = " << d3 << endl;

	// cout << "Enter a complex number (real imag) for c1:\n";
	cin >> real_1 >> imag_1;

	Handle c1(real_1, imag_1);
	Handle c2(c1);
	Handle c3 = c1;

	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;

	return;
}

void Sample3() {
	/*
		Goal:
			- Test the operator overloading (+, -, *, /)
	*/
	double double_1, double_2;
	double real_1, imag_1, real_2, imag_2;

	// cout << "Enter a double for d1:\n";
	cin >> double_1;
	// cout << "Enter a double for d2:\n";
	cin >> double_2;
	// cout << "Enter a complex number (real imag) for c1:\n";
	cin >> real_1 >> imag_1;
	// cout << "Enter a complex number (real imag) for c2:\n";
	cin >> real_2 >> imag_2;

	Handle d1(double_1);
	Handle d2(double_2);
	Handle c1(real_1, imag_1);
	Handle c2(real_2, imag_2);

	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl << endl;

	cout << "d1 + d2 = " << d1 + d2 << endl;
	cout << "d1 - d2 = " << d1 - d2 << endl;
	cout << "d1 * d2 = " << d1 * d2 << endl;
	cout << "d1 / d2 = " << d1 / d2 << endl << endl;

	cout << "c1 + c2 = " << c1 + c2 << endl;
	cout << "c1 - c2 = " << c1 - c2 << endl;
	cout << "c1 * c2 = " << c1 * c2 << endl;
	cout << "c1 / c2 = " << c1 / c2 << endl << endl;

	cout << "d1 + c1 = " << d1 + c1 << endl;
	cout << "d1 - c1 = " << d1 - c1 << endl;
	cout << "d1 * c1 = " << d1 * c1 << endl;
	cout << "d1 / c1 = " << d1 / c1 << endl << endl;

	cout << "c2 + d2 = " << c2 + d2 << endl;
	cout << "c2 - d2 = " << c2 - d2 << endl;
	cout << "c2 * d2 = " << c2 * d2 << endl;
	cout << "c2 / d2 = " << c2 / d2 << endl;

	return;
}

void Sample4(){
	/*
		Goal:
			- Test the operator overloading (+=, -=, *=, /=)
	*/
	double double_1, double_2;
	double real_1, imag_1, real_2, imag_2;

	// cout << "Enter a double for d1:\n";
	cin >> double_1;
	// cout << "Enter a double for d2:\n";
	cin >> double_2;
	// cout << "Enter a complex number (real imag) for c1:\n";
	cin >> real_1 >> imag_1;
	// cout << "Enter a complex number (real imag) for c2:\n";
	cin >> real_2 >> imag_2;

	Handle d1(double_1);
	Handle d2(double_2);
	Handle c1(real_1, imag_1);
	Handle c2(real_2, imag_2);
	
	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl << endl;

	d1 += d2; cout << "d1 += d2; d1 = " << d1 << endl;
	d1 *= d2; cout << "d1 *= d2; d1 = " << d1 << endl;
	d1 -= d2; cout << "d1 -= d2; d1 = " << d1 << endl;
	d1 /= d2; cout << "d1 /= d2; d1 = " << d1 << endl << endl;

	c1 += c2; cout << "c1 += c2; c1 = " << c1 << endl;
	c1 *= c2; cout << "c1 *= c2; c1 = " << c1 << endl;
	c1 -= c2; cout << "c1 -= c2; c1 = " << c1 << endl;
	c1 /= c2; cout << "c1 /= c2; c1 = " << c1 << endl << endl;

	d1 += c2; cout << "d1 += c2; d1 = " << d1 << endl;
	d1 = d2; cout << "d1 = d2;  d1 = " << d1 << endl;
	d1 *= c2; cout << "d1 *= c2; d1 = " << d1 << endl;
	d1 = d2; cout << "d1 = d2;  d1 = " << d1 << endl;
	d1 -= c2; cout << "d1 -= c2; d1 = " << d1 << endl;
	d1 = d2; cout << "d1 = d2;  d1 = " << d1 << endl;
	d1 /= c2; cout << "d1 /= c2; d1 = " << d1 << endl << endl;

	c1 += d2; cout << "c1 += d2; c1 = " << c1 << endl;
	c1 *= d2; cout << "c1 *= d2; c1 = " << c1 << endl;
	c1 -= d2; cout << "c1 -= d2; c1 = " << c1 << endl;
	c1 /= d2; cout << "c1 /= d2; c1 = " << c1 << endl;

	return;
}

int main() {
	int choice;
	// cout << "Enter a choice for the sample program:\n";
	cin >> choice;

	if (choice == 1)
		Sample1();
	else if (choice == 2)
		Sample2();
	else if (choice == 3)
		Sample3();
	else if (choice == 4)
		Sample4();

	return 0;
}

//############################# Do not modify the code above #############################//