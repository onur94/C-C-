#include <iostream>
#include "classa.h"
#include "classb.h"

using namespace std;

int main() {
	class_a cls_a;
	class_b cls_b;

	cls_b.printX();
	cls_a.setX(10);
	cls_b.printX();

	return 0;
}
