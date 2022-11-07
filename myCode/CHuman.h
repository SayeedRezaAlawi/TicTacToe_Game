/*
 * CHuman.h
 *
 *      Author: Sayeed Reza Alawi
 */
#ifndef CHUMAN_H
#define CHUMAN_H
#include "CPlayer.h"

/**
 * This class enables user to play the game against human or computer.
 *
 */
class CHuman: public CPlayer
{
private:
	/**
	 * @param m_inputRowPosition input row position entered by user.
	 */
	unsigned short m_inputRowPosition = 0;
	/**
	 * @param m_inputColPosition input columns position entered by user.
	 */
	unsigned short m_inputColPosition = 0;
public:
	/**
	 * Constructor of human player.
	 */
	CHuman();
	/**
	 * Destructor of human player.
	 */
	~CHuman();
	/**
	 * Method to place a stone on board in each round.
	 * @param stone index of player.
	 */
	bool placeStone(unsigned short stone);
	/**
	 * Check the board for any winner.
	 * @param stone index of player.
	 */
	bool winnerEvaluation(unsigned short stone);

};

#endif /* CHUMAN_H */
