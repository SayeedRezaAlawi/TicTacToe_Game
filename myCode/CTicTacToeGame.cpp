/*
 * CTicTacToeGame.cpp
 *
 *      Author: Sayeed Reza Alawi
 */

#include "CTicTacToeGame.h"
#include "CTicTacToeBoard.h"
#include "CComputer.h"
#include "CHuman.h"
#include <iostream>
#include <stdlib.h>
#include "CPlayer.h"
#include "CGUIScreen.h"
#include "CCRTScreen.h"
using namespace std;

CTicTacToeGame::CTicTacToeGame()
{
	int choice = 1;
		if (choice == 1)
		{
			m_pScreen = new CCRTScreen;
		} else if (choice == 2)
		{
			m_pScreen = new CGUIScreen;
		}
		else
		{
			m_pScreen = 0;
		}
	CComputer computer;
	CHuman human;
	CTicTacToeBoard board;
	m_TicTacToeBoard = board;
}
CTicTacToeGame::~CTicTacToeGame()
{

}
void CTicTacToeGame::run()
{
	m_pScreen->addElement(&m_TicTacToeBoard);
	selectPlayer(0);
	selectPlayer(1);
	m_pPlayerType[0]->addBoard(&m_TicTacToeBoard);
	m_pPlayerType[1]->addBoard(&m_TicTacToeBoard);
	play();
}

void CTicTacToeGame::selectPlayer(unsigned short player)
{
	unsigned short inputcheck = 0;
	switch (player)
	{
	case 0:
		while (inputcheck == 0)
		{
			cout << "Select player: 1 (1 - human, 2 - computer) : ";

			cin >> m_playerType;
			if (m_playerType == 1 || m_playerType == 2)
			{
				inputcheck = 1;
				break;
			}
			cout << "Wrong player index is entered please try again. " << endl;
		}

		if (m_playerType == 1)
		{
			m_pPlayerType[0] = new CHuman;
			cout << "Human Player selected" << endl;
			break;
		}
		else
		{
			m_pPlayerType[0] = new CComputer;
			cout << "Computer Player selected" << endl;
			break;
		}

	case 1:
		inputcheck = 0;
		while (inputcheck == 0)
		{
			cout << "Select player: 2 (1 - human, 2 - computer) : ";
			cin >> m_playerType;
			if (m_playerType == 1 || m_playerType == 2)
			{
				inputcheck = 1;
				break;
			}
			cout << "Wrong player index is entered please try again. " << endl;
		}
		if (m_playerType == 1)
		{
			m_pPlayerType[1] = new CHuman;
			cout << "Human Player selected" << endl;
			break;
		}
		else
		{
			m_pPlayerType[1] = new CComputer;
			cout << "Computer Player selected" << endl;
			break;
		}
	}
}

void CTicTacToeGame::play()
{
	m_pScreen->print();
	for (unsigned short i = 0; i < 9; i++)
	{
		cout << "Placing a stone in round " << i + 1 << endl;
		bool finished = m_pPlayerType[i % 2]->placeStone((i % 2) + 1);
		m_pScreen->print();
		if (finished)
		{
			cout << "We have a winner!!!" << endl;
			return;
		}
	}
	cout << "Draw...." << endl;
}
