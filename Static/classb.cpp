/*
 * classb.cpp
 *
 *  Created on: 26 Eyl 2022
 *      Author: Onur
 */

#include "classb.h"

class_b::class_b() {
	// TODO Auto-generated constructor stub

}

class_b::~class_b() {
	// TODO Auto-generated destructor stub
}

void class_b::setx(int value)
{
	class_a::x = value;
}

int class_b::getx()

{
	return class_a::x;
}
