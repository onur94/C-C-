/*
 * operation.cpp
 *
 *  Created on: 19 Eyl 2022
 *      Author: Onur
 */

#include "operation.h"

operation::operation() {
	// TODO Auto-generated constructor stub
	initializeHandlers();
}

operation::~operation() {
	// TODO Auto-generated destructor stub
}

void operation::initializeHandlers()
{
	handlerMap.insert(pair<int, pfunc>(OP_ADD, &operation::addOperation));
	handlerMap.insert(pair<int, pfunc>(OP_SUB, &operation::subOperation));
	handlerMap.insert(pair<int, pfunc>(OP_MUL, &operation::mulOperation));
	handlerMap.insert(pair<int, pfunc>(OP_DIV, &operation::divOperation));
}

void operation::register_handler(functionHandler *fHandler)
{
	this->fHandler = fHandler;
}

void operation::callFunction(int ID, int a, int b)
{
	pfunc f = handlerMap[ID];
	(*f)(a, b, fHandler);
}

void operation::addOperation(int a, int b, functionHandler *fhandler)
{
	fhandler->add(a, b);
}

void operation::subOperation(int a, int b, functionHandler *fhandler)
{
	fhandler->sub(a, b);
}

void operation::mulOperation(int a, int b, functionHandler *fhandler)
{
	fhandler->mul(a, b);
}

void operation::divOperation(int a, int b, functionHandler *fhandler)
{
	fhandler->div(a, b);
}
