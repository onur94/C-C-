//============================================================================
// Name        : friend.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "classbase.h"
#include "classfriend.h"

using namespace std;

int main() {
	class_base cls_base;
	class_friend cls_friend(5);

	cls_base.setFriend(&cls_friend);
	cls_base.getX();

	return 0;
}
