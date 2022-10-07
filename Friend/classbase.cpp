/*
 * classbase.cpp
 *
 *  Created on: 7 Eki 2022
 *      Author: Onur
 */

#include "classbase.h"
#include "classfriend.h"

class_base::class_base() {
	clsf = nullptr;
}

class_base::~class_base() {
}

void class_base::setFriend(class_friend *clsf)
{
	this->clsf = clsf;
}

void class_base::getX()
{
	cout << "class friend private x value: " << clsf->x << endl;
}
