/*
 * CCRTScreen.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CCRTSCREEN_H
#define CCRTSCREEN_H
#include "CScreen.h"

/**
 * Special CScreen type which has inheritance relashionship with CScreen class.
 *
 */
class CCRTScreen: public CScreen
{
public:
	/**
	 * Print the board on CRT console.
	 */
	void print();
};

#endif /* CCRTSCREEN_H */
