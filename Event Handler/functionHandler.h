/*
 * functionHandler.h
 *
 *  Created on: 19 Eyl 2022
 *      Author: Onur
 */

#ifndef FUNCTIONHANDLER_H_
#define FUNCTIONHANDLER_H_

class functionHandler {
public:
	virtual void add(int, int) = 0;
	virtual void sub(int, int) = 0;
	virtual void mul(int, int) = 0;
	virtual void div(int, int) = 0;
};

#endif /* FUNCTIONHANDLER_H_ */
