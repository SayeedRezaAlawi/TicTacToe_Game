/*
 * CTicTacToeBoard.cpp
 *
 *      Author: Sayeed Reza Alawi
 */

#include "CTicTacToeBoard.h"
#include <iostream>
#include <stdlib.h>
#include "CScreen.h"
#include "CPlayer.h"
using namespace std;


CTicTacToeBoard::CTicTacToeBoard() :
		CBoard(3, 3, "TicTacToe")
{

}

CTicTacToeBoard::~CTicTacToeBoard()
{
}

unsigned short CTicTacToeBoard::countRow(unsigned short noStone,
		unsigned short noEmpty, unsigned short stone)
{
	m_Row = 0;
	m_Col = 0;
	m_DiagLefDwn = 0;
	m_DiagLefUp = 0;

	unsigned short notOccupied = 0;
	unsigned short countRow = 0;
	for (unsigned short row = 0; row < 3; row++)
	{
		for (unsigned short col = 0; col < 3; col++)
		{
			if (stone == getFieldStateAt(row, col))
			{
				countRow++;
			}
			else if (0 == getFieldStateAt(row, col))
			{
				notOccupied++;
			}
		}
		if (countRow == noStone && notOccupied == noEmpty)
		{
			m_Row = row + 1;

		}
		else
		{
			notOccupied = 0;
			countRow = 0;
		}
	}
	return m_Row;
}

unsigned short CTicTacToeBoard::countColumn(unsigned short noStone,
		unsigned short noEmpty, unsigned short stone)
{
	m_Row = 0;
	m_Col = 0;
	m_DiagLefDwn = 0;
	m_DiagLefUp = 0;
	unsigned short notOccupied = 0;
	unsigned short countCol = 0;
	for (unsigned short col = 0; col < 3; col++)
	{
		for (unsigned short row = 0; row < 3; row++)
		{
			if (stone == getFieldStateAt(row, col))
			{
				countCol++;
			}
			else if (0 == getFieldStateAt(row, col))
			{
				notOccupied++;
			}
		}
		if (countCol == noStone && notOccupied == noEmpty)
		{
			m_Col = col + 1;
		}
		else
		{
			notOccupied = 0;
			countCol = 0;
		}
	}
	return m_Col;
}

unsigned short CTicTacToeBoard::countDiagonalLeftDown(unsigned short noStone,
		unsigned short noEmpty, unsigned short stone)
{
	m_Row = 0;
	m_Col = 0;
	m_DiagLefDwn = 0;
	m_DiagLefUp = 0;
	unsigned short notOccupied = 0;
	unsigned short countDigLeftDown = 0;
	for (unsigned short diag = 0; diag < 3; diag++)
	{
		if (stone == getFieldStateAt(diag, diag))
		{
			countDigLeftDown++;
		}
		if (0 == getFieldStateAt(diag, diag))
		{
			notOccupied++;
		}
	}
	if ((countDigLeftDown == noStone) && (notOccupied == noEmpty))
	{
		return 1;
	}
	return 0;
}

unsigned short CTicTacToeBoard::countDiagonalLeftUp(unsigned short noStone,
		unsigned short noEmpty, unsigned short stone)
{
	m_Row = 0;
	m_Col = 0;
	m_DiagLefDwn = 0;
	m_DiagLefUp = 0;
	if (stone == getFieldStateAt(2, 0) && stone == getFieldStateAt(1, 1)
			&& 0 == getFieldStateAt(0, 2))
	{
		return 2;
	}
	else if (stone == getFieldStateAt(2, 0) && 0 == getFieldStateAt(1, 1)
			&& stone == getFieldStateAt(0, 2))
	{
		return 2;
	}
	else if (0 == getFieldStateAt(2, 0) && stone == getFieldStateAt(1, 1)
			&& stone == getFieldStateAt(0, 2))
	{
		return 2;
	}
////////////////////////
	else if (stone == getFieldStateAt(2, 0) && 0 == getFieldStateAt(1, 1)
			&& 0 == getFieldStateAt(0, 2))
	{
		return 3;
	}
	else if (0 == getFieldStateAt(2, 0) && 0 == getFieldStateAt(1, 1)
			&& stone == getFieldStateAt(0, 2))
	{
		return 3;
	}
	else if (0 == getFieldStateAt(2, 0) && stone == getFieldStateAt(1, 1)
			&& 0 == getFieldStateAt(0, 2))
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

unsigned short CTicTacToeBoard::boardempty()
{
	unsigned short notOccupied = 0;
	for (unsigned short row = 0; row < 3; row++)
	{
		for (unsigned short col = 0; col < 3; col++)
		{
			if (0 == getFieldStateAt(row, col))
			{
				notOccupied++;
			}
		}
	}
	if (notOccupied == 9)
	{
		return notOccupied;
	}
	else if (notOccupied == 8)
	{
		return notOccupied;
	}
	else if (notOccupied == 4)
	{
		return notOccupied;
	}
	else if (notOccupied == 3)
	{
		return notOccupied;
	}
	else if (notOccupied == 2)
	{
		return notOccupied;
	}
	else if (notOccupied == 1)
	{
		return notOccupied;
	}
	return 0;
}
