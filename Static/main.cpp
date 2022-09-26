//============================================================================
// Name        : static_test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "classb.h"

using namespace std;

int class_a::x = 5;

int main() {
	class_b cls_b;
	class_a cls_a;

	cout << cls_b.getx() << endl;
	cls_b.setx(10);
	cls_a.print_x();

	return 0;
}
