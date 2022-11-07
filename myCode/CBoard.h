/*
 * CBoard.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CBOARD_H
#define CBOARD_H
#include <string>
#include "CPosition.h"

/**
 * Creates a Generic Game Board with row and column size
 * and let player to put a new piece on board. It provide number of
 * player or opponent player stone in each row, columns and diagonals.
 * User also have access to each field by get and set methods.
 *
 */

class CBoard
{
private:
	/**
	 * @param m_Type store type of Board name.
	 */
	std::string m_Type;

	/**
	 * @param field_s define a enumeration type for field state.
	 */
	enum field_s
	{
		NotOccupied = 0, X = 1, O = 2,
	};
	/**
	 * @param **m_fields is a 2D dynamic memory and allocated to retain state on each
	 * field of board.
	 */
	field_s **m_fields;
	/**
	 * @param m_cols is used to store column size of board.
	 */
	unsigned short m_cols = 3;
	/**
	 * @param m_rows is used to store row size of board.
	 */
	unsigned short m_rows = 3;
public:
	/**
	 * Constructor of Board which allocate a 2D memory array
	 * to create board and hold each field state.
	 * @param row is number of rows.
	 * @param cols is number of columns.
	 * @param type is name of game board.
	 */
	CBoard(unsigned short row, unsigned short cols, std::string type);
	/**
	 * Destructor of Board which frees allocated memory.
	 */
	virtual ~CBoard();
	/**
	 * Virtual method: Set stone on the board
	 * @param row row number of board which player wants to put new stone.
	 * @param col column number of board which player wants to put new stone.
	 * @param stone type of stone which player wants to put in defined position
	 * on board.
	 */
	virtual void setFieldStateAt(unsigned short row, unsigned short col,
			unsigned short stone);
	/**
	 * Virtual method: Returns the state of defined field by parameters x and y.
	 * @param row row number of board which player wants to get the state.
	 * @param col column number of board which player wants to get the state.
	 */
	unsigned short getFieldStateAt(unsigned short row, unsigned short col);
	/**
	 * Virtual method: returns number of player or opponent stone in each row.
	 * @param noStone number of stone which player set for condition of return.
	 * @param noEmpty number of empty position which player set for condition of return.
	 * @param stone type of stone.
	 */
	virtual unsigned short countRow(unsigned short noStone,
			unsigned short noEmpty, unsigned short stone) = 0;
	/**
	 * Virtual method: returns number of player or opponent stone in each column.
	 * @param noStone number of stone which player set for condition of return.
	 * @param noEmpty number of empty position which player set for condition of return.
	 * @param stone type of stone.
	 */
	virtual unsigned short countColumn(unsigned short noStone,
			unsigned short noEmpty, unsigned short stone) =0;
	/**
	 * Virtual method: returns number of player or opponent stone in left down diagonal.
	 * @param noStone number of stone which player set for condition of return.
	 * @param noEmpty number of empty position which player set for condition of return.
	 * @param stone type of stone.
	 */
	virtual unsigned short countDiagonalLeftDown(unsigned short noStone,
			unsigned short noEmpty, unsigned short stone) =0;
	/**
	 * Virtual method: returns number of player or opponent stone in left up diagonal.
	 * @param noStone number of stone which player set for condition of return.
	 * @param noEmpty number of empty position which player set for condition of return.
	 * @param stone type of stone.
	 */
	virtual unsigned short countDiagonalLeftUp(unsigned short noStone,
			unsigned short noEmpty, unsigned short stone) =0;
	/**
	 * Virtual method: checks if board is empty or not, it can also return number of empty fields in return statement.
	 */
	virtual unsigned short boardempty() =0;
	/**
	 * Print the board.
	 */
	void print();
};

#endif /* CBOARD_H */
