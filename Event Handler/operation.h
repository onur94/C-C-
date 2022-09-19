/*
 * operation.h
 *
 *  Created on: 19 Eyl 2022
 *      Author: Onur
 */

#ifndef OPERATION_H_
#define OPERATION_H_

#include <iostream>
#include <map>
#include "functionHandler.h"

#define OP_ADD 1
#define OP_SUB 2
#define OP_MUL 3
#define OP_DIV 4

using pfunc = void(*)(int, int, functionHandler *);

using namespace std;

class operation {
public:
	operation();
	void register_handler(functionHandler *);
	void callFunction(int, int, int);
	virtual ~operation();

private:
	void initializeHandlers();
	functionHandler *fHandler;
	map<int, pfunc> handlerMap;

	static void addOperation(int, int, functionHandler *);
	static void subOperation(int, int, functionHandler *);
	static void mulOperation(int, int, functionHandler *);
	static void divOperation(int, int, functionHandler *);
};

#endif /* OPERATION_H_ */
