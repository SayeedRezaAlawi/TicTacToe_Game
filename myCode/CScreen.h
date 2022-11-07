/*
 * CScreen.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CSCREEN_H
#define CSCREEN_H
#include "CBoard.h"

/**
 * Generic CScreen type which receives can inheritance.
 *
 */
class CScreen
{
private:
	/**
	 * @param m_pBoard pointer to generic board. Aggregation relationship!
	 * @link aggregation
	 */
	CBoard *m_pBoard;
public:
	/**
	 * Constructor of CScreen class.
	 */
	CScreen();
	/**
	 * Virtual destructor.
	 */
	virtual ~CScreen();
	/**
	 * to access generic board through the address of special board type.
	 * @param element pointer points to special board address.
	 */
	void addElement(CBoard *element);
	/**
	 * Pure virtual print method which make enables polymorphism.
	 */
	virtual void print() =0;
	friend class CCRTScreen;
};

#endif /* CSCREEN_H */
