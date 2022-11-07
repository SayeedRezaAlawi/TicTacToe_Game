/*
 * CComputer.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CCOMPUTER_H
#define CCOMPUTER_H
#include "CPlayer.h"

/**
 * Computer Player which plays based on finding best position
 * or defence position on the board.
 *
 */
class CComputer: public CPlayer
{
private:
	/**
	 * @param Move structure type which include row and columns of different
	 * scanning algorithm.
	 * @param row indicates row number.
	 * @param row indicates column number
	 * @param bestposition a structure to maintain best row and column position.
	 */
	struct Move
	{
		unsigned short row, col;
	};
	Move bestposition;
	/**
	 * @param m_player defines type of stone in each round.
	 */
	unsigned short m_player = 0;
	/**
	 * @param m_opponent defines type of opponent stone in each round.
	 */
	unsigned short m_opponent = 0;
public:
	/**
	 * Constructor of computer player.
	 */
	CComputer();
	/**
	 * Method to place a stone on board in each round.
	 * @param stone index of player.
	 */
	bool placeStone(unsigned short stone);
	/**
	 * find best position to defence against opponent.
	 * @param stone index of player.
	 */
	bool defence(unsigned short stone);
	/**
	 * find best position to win the game.
	 * @param stone index of player.
	 */
	bool bestPosition(unsigned short stone);
	/**
	 * find arbitrary position to continue the game.
	 * @param stone index of player.
	 */
	bool normalPosition(unsigned short stone);

};

#endif /* CCOMPUTER_H */
