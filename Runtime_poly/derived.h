/*
 * derived.h
 *
 *  Created on: 3 Eki 2022
 *      Author: Onur
 */

#ifndef DERIVED_H_
#define DERIVED_H_

#include <iostream>
#include "base.h"

using namespace std;

// derived class is inherited from base class
class derived : public base {
	
public:
	derived();
	void function(int) override;
};

#endif /* DERIVED_H_ */
