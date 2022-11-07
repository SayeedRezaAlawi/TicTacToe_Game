/*
 * CTicTacToeGame.h
 *
 *      Author: Sayeed Reza Alawi
 */

#ifndef CGAME_H
#define CGAME_H
#include "CTicTacToeBoard.h"
#include "CScreen.h"
#include "CComputer.h"
#include "CHuman.h"
#include "CPlayer.h"

/**
 * This class is main class which creates all other classes and pass pointers.
 *
 */
class CTicTacToeGame
{
private:
	/**
	 * @param m_pScreen pointer to generic screen. composition relationship!
	 * @link aggregationByValue
	 */
	CScreen *m_pScreen;
	/**
	 * @param m_TicTacToeBoard composition relationship! creates CTicTacToeBoard m_TicTacToeBoard instance.
	 * @link aggregationByValue
	 */
	CTicTacToeBoard m_TicTacToeBoard;
	/**
	 * @param m_playerType attributes defines type of player.
	 */
	unsigned short m_playerType;
	/**
	 * @param m_pPlayerType pointer to generic player class. composition relationship!
	 * @link aggregationByValue
	 */
	CPlayer *m_pPlayerType[2];
public:
	/**
	 * Constructor of game.
	 */
	CTicTacToeGame();
	/**
	 * destructor of game.
	 */
	~CTicTacToeGame();
	/**
	 * Run the game.
	 */
	void run();
	/**
	 * Enables to select Human or Computer players.
	 */
	void selectPlayer(unsigned short player);
	/**
	 * Start the game and plays each round.
	 */
	void play();
};

#endif /* CTICTACTOEGAME_H */
