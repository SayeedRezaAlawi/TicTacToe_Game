/*
 * CPosition.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CPOSITION_H_
#define CPOSITION_H_
#include "CBoard.h"

/**
 * A CPosition class describes a specific position on the board game.
 * The CPosition Object knows the size of the board (number of rows and columns).
 * The size attribute may only be set by the CBoard class, while the board is being
 * constructed.
 *
 */

class CPosition
{
private:
	/**
	 * @param size size of board.
	 */
	int size;
	/**
	 * @param static attributes m_noRows number of rows which not changed after
	 * every object creation.
	 */
	static int m_noRows;
	/**
	 * @param static attributes m_noColumns number of columns which not changed after
	 * every object creation.
	 */
	static int m_noColumns;
	/**
	 * @param m_row shows a specific row number.
	 */
	unsigned short m_row;
	/**
	 * @param m_col shows a specific column number.
	 */
	unsigned short m_col;

public:
	/**
	 * Constructor of Position Class.
	 */
	CPosition();
	/**
	 * Destructor of Position Class.
	 */
	virtual ~CPosition();
	/**
	 * @param CBoard friend class to access methods and attributes of this class.
	 */
	friend class CBoard;
	/**
	 * Static method to set size of board in CPosition class.
	 * @param row is row number.
	 * @param cols is column number.
	 */
	static void setSize(unsigned short row, unsigned short cols);

	/**
	 * Method to get row number.
	 * @param row is row number.
	 */
	unsigned short getRow(unsigned short row);
	/**
	 * Method to get column number.
	 * @param cols is column number.
	 */
	unsigned short getColumn(unsigned short col);

};

#endif /* CPOSITION_H_ */
