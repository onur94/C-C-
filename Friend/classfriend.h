/*
 * classfriend.h
 *
 *  Created on: 7 Eki 2022
 *      Author: Onur
 */

#ifndef CLASSFRIEND_H_
#define CLASSFRIEND_H_

#include "classbase.h"

class class_friend {
public:
	class_friend(int);
	~class_friend();

	friend void class_base::getX(); // class_base can access to the private variable of class_friend within getX function.
private:
	int x;
};

#endif /* CLASSFRIEND_H_ */
