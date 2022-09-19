/*
 * mathematics.h
 *
 *  Created on: 19 Eyl 2022
 *      Author: Onur
 */

#ifndef MATHEMATICS_H_
#define MATHEMATICS_H_

#include <iostream>
#include "functionHandler.h"

using namespace std;

class mathematics : public functionHandler {
public:
	mathematics();
	void add(int, int);
	void sub(int, int);
	void mul(int, int);
	void div(int, int);
	virtual ~mathematics();
};

#endif /* MATHEMATICS_H_ */
