//============================================================================
// Name        : runtime_poly.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Method overriding example
//============================================================================

#include <iostream>
#include "derived.h"

using namespace std;

int main() 
{
	base *cls = new derived();
	cls->function();
	return 0;
}
