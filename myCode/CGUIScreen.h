/*
 * CGUIScreen.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CGUISCREEN_H
#define CGUISCREEN_H
#include "CScreen.h"

/**
 * Special CScreen type which has inheritance relashionship with CScreen class.
 *
 */
class CGUIScreen: public CScreen
{
public:
	/**
	 * Print the board on CRT console.
	 */
	void print();
};

#endif /* CGUISCREEN_H */
