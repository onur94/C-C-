/*
 * base.h
 *
 *  Created on: 3 Eki 2022
 *      Author: Onur
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>

using namespace std;

class base {
public:
	base();
	void base_function();
	virtual void derived_function(int) = 0; // pure virtual function
	virtual ~base();
};

#endif /* BASE_H_ */
