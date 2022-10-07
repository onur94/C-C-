/*
 * classbase.h
 *
 *  Created on: 7 Eki 2022
 *      Author: Onur
 */

#ifndef CLASSBASE_H_
#define CLASSBASE_H_

#include <iostream>

using namespace std;

class class_friend;

class class_base {
public:
	class_base();
	void setFriend(class_friend *);
	void getX();
	~class_base();
private:
	class_friend *clsf;
};

#endif /* CLASSBASE_H_ */
