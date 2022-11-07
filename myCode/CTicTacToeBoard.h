/*
 * CTicTacToeBoard.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CTICTACTOEBOARD_H
#define CTICTACTOEBOARD_H
#include "CBoard.h"

/**
 * Creates a specific game board by inheritance of a generic game board.
 * This class enables player to put a new stone on board. It provide number of
 * player or opponent player stone in each row, columns and diagonals.
 *
 *
 */
class CTicTacToeBoard: public CBoard
{
private:
	/**
	 * @param m_Row define the row number.
	 */
	unsigned short m_Row = 0;
	/**
	 * @param m_Col define the column number.
	 */
	unsigned short m_Col = 0;
	/**
	 * @param m_DiagLefDwn define the left down diagonal.
	 */
	unsigned short m_DiagLefDwn = 0;
	/**
	 * @param m_DiagLefUp define the left up diagonal.
	 */
	unsigned short m_DiagLefUp = 0;
public:
	/**
	 * Constructor of TicTacToe Board which initialize generic board.
	 */
	CTicTacToeBoard();
	/**
	 * Destructor of TicTacToe Board.
	 */
	~CTicTacToeBoard();
	/**
	 * Returns number of player or opponent stone in each row.
	 * @param noStone number of stone which player set for condition of return.
	 * @param noEmpty number of empty position which player set for condition of return.
	 * @param stone type of stone.
	 */
	unsigned short countRow(unsigned short noStone, unsigned short noEmpty,
			unsigned short stone);
	/**
	 * Returns number of player or opponent stone in each column.
	 * @param noStone number of stone which player set for condition of return.
	 * @param noEmpty number of empty position which player set for condition of return.
	 * @param stone type of stone.
	 */
	unsigned short countColumn(unsigned short noStone, unsigned short noEmpty,
			unsigned short stone);
	/**
	 * Returns number of player or opponent stone in left down diagonal.
	 * @param noStone number of stone which player set for condition of return.
	 * @param noEmpty number of empty position which player set for condition of return.
	 * @param stone type of stone.
	 */
	unsigned short countDiagonalLeftDown(unsigned short noStone,
			unsigned short noEmpty, unsigned short stone);
	/**
	 * Returns number of player or opponent stone in left up diagonal.
	 * @param noStone number of stone which player set for condition of return.
	 * @param noEmpty number of empty position which player set for condition of return.
	 * @param stone type of stone.
	 */
	unsigned short countDiagonalLeftUp(unsigned short noStone,
			unsigned short noEmpty, unsigned short stone);
	/**
	 * check if board is empty or not, it can also return number of empty fields in return statement.
	 */
	unsigned short boardempty();
};

#endif /* CTICTACTOEBOARD_H */
