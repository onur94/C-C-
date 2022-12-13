#include <iostream>
#include "mathematics.h"
#include "operation.h"

using namespace std;

int main() {
	mathematics *math = new mathematics;
	operation op;

	op.register_handler((functionHandler *)math);
	op.callFunction(OP_ADD, 1, 3);
	op.callFunction(OP_SUB, 4, 6);
	op.callFunction(OP_MUL, 2, 5);
	op.callFunction(OP_DIV, 10, 3);

	return 0;
}
