/*
 * CPlayer.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CPLAYER_H
#define CPLAYER_H
#include "CBoard.h"

/**
 * Generic Player which receives inheritance from computer
 * or human players.
 *
 */
class CPlayer
{
private:
	/**
	 * @param m_pBoard pointer to generic board. Aggregation relationship!
	 * @link aggregation
	 */
	CBoard *m_pBoard;
public:
	/**
	 * Constructor of CPlayer class.
	 */
	CPlayer();
	/**
	 * Destructor of CPlayer.
	 */
	virtual ~CPlayer();
	/**
	 * @param CComputer friend class to access methods and attributes of this class.
	 */
	friend class CComputer;
	/**
	 * @param CHuman friend class to access methods and attributes of this class.
	 */
	friend class CHuman;
	/**
	 * Virtual method: to place a stone on board in each round.
	 * @param stone index of player.
	 */

	virtual bool placeStone(unsigned short stone) = 0;
	/**
	 * to access generic board through the address of special board type.
	 * @param element pointer points to special board address.
	 */
	void addBoard(CBoard *element);
};

#endif /* CPLAYER_H */
