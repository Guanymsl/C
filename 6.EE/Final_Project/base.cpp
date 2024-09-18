/* base.cpp */

#include <iostream>
#include "base.h"
using namespace std;

Base::Base(): use(1) {}

Base& Base::operator= (const Base& b) {
	use = b.use;
	return *this;
}