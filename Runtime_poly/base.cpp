/*
 * base.cpp
 *
 *  Created on: 3 Eki 2022
 *      Author: Onur
 */

#include "base.h"

base::base() {
	// TODO Auto-generated constructor stub
}

base::~base() {
	// TODO Auto-generated destructor stub
}

void base::base_function()
{
	cout << "Base class function called" << endl;
	this->derived_function(5);
}
