#include <iostream>
#include "derived.h"

using namespace std;

int main() 
{
	base *cls = new derived();
	cls->function();
	return 0;
}
