/*
 * CComputer.cpp
 *
 *      Author: Sayeed Reza Alawi
 */

#include "CComputer.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

CComputer::CComputer() :
		CPlayer()
{

}

bool CComputer::placeStone(unsigned short stone)
{
	if (stone == 1)
	{
		m_player = 1;
		m_opponent = 2;

	}
	else
	{
		m_player = 2;
		m_opponent = 1;
	}

	if (bestPosition(m_player) == true)
	{
		m_pBoard->setFieldStateAt(bestposition.row, bestposition.col, m_player);
		return true;
	}

	else if (defence(m_opponent) == true)
	{
		cout << "Found defense diagonal: (" << bestposition.row << ", "
				<< bestposition.col << ")" << endl;
		m_pBoard->setFieldStateAt(bestposition.row, bestposition.col, m_player);
		return false;
	}

	else if (normalPosition(m_player) == true)
	{
		m_pBoard->setFieldStateAt(bestposition.row, bestposition.col, m_player);
		return false;
	}

	return false;
}

bool CComputer::defence(unsigned short stone)
{
	unsigned short bestRow = 0;
	unsigned short bestCol = 0;
	unsigned short bestDigLeftDown = 0;
	unsigned short bestDigLeftUp = 0;

	bestRow = m_pBoard->countRow(2, 1, stone);

	bestCol = m_pBoard->countColumn(2, 1, stone);

	bestDigLeftDown = m_pBoard->countDiagonalLeftDown(2, 1, stone);

	bestDigLeftUp = m_pBoard->countDiagonalLeftUp(2, 1, stone);

	if (bestRow > 0)
	{
		for (unsigned short col = 0; col < 3; col++)
		{
			if (m_pBoard->getFieldStateAt(bestRow - 1, col) == 0)
			{
				bestposition.row = bestRow - 1;
				bestposition.col = col;
			}
		}
		return true;
	}

	else if (bestCol > 0)
	{
		for (unsigned short row = 0; row < 3; row++)
		{
			if (m_pBoard->getFieldStateAt(row, bestCol - 1) == 0)
			{
				bestposition.row = row;
				bestposition.col = bestCol - 1;
			}
		}
		return true;
	}

	else if (bestDigLeftDown == 1)
	{
		for (unsigned short dig = 0; dig < 3; dig++)
		{
			if (m_pBoard->getFieldStateAt(dig, dig) == 0)
			{
				bestposition.row = dig;
				bestposition.col = dig;
			}
		}
		return true;
	}

	else if (bestDigLeftUp == 2)
	{
		if (m_pBoard->getFieldStateAt(2, 0) == 0)
		{
			bestposition.row = 2;
			bestposition.col = 0;
		}
		else if (m_pBoard->getFieldStateAt(1, 1) == 0)
		{
			bestposition.row = 1;
			bestposition.col = 1;
		}
		else if (m_pBoard->getFieldStateAt(0, 2) == 0)
		{
			bestposition.row = 0;
			bestposition.col = 2;
		}
		return true;
	}
	return false;
}

bool CComputer::bestPosition(unsigned short stone)
{
	unsigned short bestRow = 0;
	unsigned short bestCol = 0;
	unsigned short bestDigLeftDown = 0;
	unsigned short bestDigLeftUp = 0;

	bestRow = m_pBoard->countRow(2, 1, stone);

	bestCol = m_pBoard->countColumn(2, 1, stone);

	bestDigLeftDown = m_pBoard->countDiagonalLeftDown(2, 1, stone);

	bestDigLeftUp = m_pBoard->countDiagonalLeftUp(2, 1, stone);

	if (bestRow > 0)
	{
		for (unsigned short col = 0; col < 3; col++)
		{
			if (m_pBoard->getFieldStateAt(bestRow - 1, col) == 0)
			{
				bestposition.row = bestRow - 1;
				bestposition.col = col;
			}
		}
		return true;
	}

	else if (bestCol > 0)
	{
		for (unsigned short row = 0; row < 3; row++)
		{
			if (m_pBoard->getFieldStateAt(row, bestCol - 1) == 0)
			{
				bestposition.row = row;
				bestposition.col = bestCol - 1;
			}
		}
		return true;
	}

	else if (bestDigLeftDown == 1)
	{
		for (unsigned short dig = 0; dig < 3; dig++)
		{
			if (m_pBoard->getFieldStateAt(dig, dig) == 0)
			{
				bestposition.row = dig;
				bestposition.col = dig;
			}
		}
		return true;
	}

	else if (bestDigLeftUp == 2)
	{
		if (m_pBoard->getFieldStateAt(2, 0) == 0)
		{
			bestposition.row = 2;
			bestposition.col = 0;
		}
		else if (m_pBoard->getFieldStateAt(1, 1) == 0)
		{
			bestposition.row = 1;
			bestposition.col = 1;
		}
		else if (m_pBoard->getFieldStateAt(0, 2) == 0)
		{
			bestposition.row = 0;
			bestposition.col = 2;
		}
		return true;
	}
	return false;
}

bool CComputer::normalPosition(unsigned short stone)
{
	unsigned short bestRow = 0;
	unsigned short bestCol = 0;
	unsigned short bestDigLeftDown = 0;
	unsigned short bestDigLeftUp = 0;

	bestRow = m_pBoard->countRow(1, 2, stone);

	bestCol = m_pBoard->countColumn(1, 2, stone);

	bestDigLeftDown = m_pBoard->countDiagonalLeftDown(1, 2, stone);

	bestDigLeftUp = m_pBoard->countDiagonalLeftUp(1, 2, stone);

	if (m_pBoard->boardempty() == 9)
	{
		bestposition.row = 1;
		bestposition.col = 1;
		return true;
	}
	else if (m_pBoard->boardempty() == 8)
	{
		unsigned short randRow = 0;
		unsigned short randCol = 0;
		unsigned short positionCheck = 0;

		while (positionCheck == 0)
		{
			randRow = rand() % 3;
			randCol = rand() % 3;
			if (m_pBoard->getFieldStateAt(randRow, randCol) == 0)
			{
				bestposition.row = randRow;
				bestposition.col = randCol;
				positionCheck = 1;
			}
		}

		return true;
	}

	else if (m_pBoard->getFieldStateAt(0, 1) == m_opponent
			&& m_pBoard->getFieldStateAt(1, 0) == m_opponent
			&& m_pBoard->getFieldStateAt(0, 0) == 0)
	{
		bestposition.row = 0;
		bestposition.col = 0;
		return true;
	}

	else if (m_pBoard->getFieldStateAt(2, 1) == m_opponent
			&& m_pBoard->getFieldStateAt(1, 0) == m_opponent
			&& m_pBoard->getFieldStateAt(2, 0) == 0)
	{
		bestposition.row = 2;
		bestposition.col = 0;
		return true;
	}

	else if (m_pBoard->getFieldStateAt(2, 1) == m_opponent
			&& m_pBoard->getFieldStateAt(1, 2) == m_opponent
			&& m_pBoard->getFieldStateAt(2, 2) == 0)
	{
		bestposition.row = 2;
		bestposition.col = 2;
		return true;
	}

	else if (m_pBoard->getFieldStateAt(0, 1) == m_opponent
			&& m_pBoard->getFieldStateAt(1, 2) == m_opponent
			&& m_pBoard->getFieldStateAt(0, 2) == 0)
	{
		bestposition.row = 0;
		bestposition.col = 2;
		return true;
	}

	else if (bestRow > 0)
	{
		if (m_pBoard->getFieldStateAt(bestRow - 1, 0) == stone
				&& m_pBoard->getFieldStateAt(bestRow - 1, 2) == 0)
		{
			bestposition.row = bestRow - 1;
			bestposition.col = 2;
		}

		else if (m_pBoard->getFieldStateAt(bestRow - 1, 1) == stone
				&& m_pBoard->getFieldStateAt(bestRow - 1, 2) == 0)
		{
			bestposition.row = bestRow - 1;
			bestposition.col = 2;
		}

		else if (m_pBoard->getFieldStateAt(bestRow - 1, 2) == stone
				&& m_pBoard->getFieldStateAt(bestRow - 1, 0) == 0)
		{
			bestposition.row = bestRow - 1;
			bestposition.col = 0;
		}
		return true;
	}

	else if (bestCol > 0)
	{

		if (m_pBoard->getFieldStateAt(0, bestCol - 1) == stone
				&& m_pBoard->getFieldStateAt(2, bestCol - 1) == 0)
		{
			bestposition.row = 2;
			bestposition.col = bestCol - 1;
		}
		else if (m_pBoard->getFieldStateAt(1, bestCol - 1) == stone
				&& m_pBoard->getFieldStateAt(2, bestCol - 1) == 0)
		{
			bestposition.row = 2;
			bestposition.col = bestCol - 1;
		}
		else if (m_pBoard->getFieldStateAt(2, bestCol - 1) == stone
				&& m_pBoard->getFieldStateAt(0, bestCol - 1) == 0)
		{
			bestposition.row = 0;
			bestposition.col = bestCol - 1;
		}

		return true;
	}

	else if (bestDigLeftDown == 1)
	{
		if (m_pBoard->getFieldStateAt(0, 0) == stone
				&& m_pBoard->getFieldStateAt(1, 1) == 0)
		{
			bestposition.row = 1;
			bestposition.col = 1;
		}
		else if (m_pBoard->getFieldStateAt(1, 1) == stone
				&& m_pBoard->getFieldStateAt(2, 2) == 0)
		{
			bestposition.row = 2;
			bestposition.col = 2;
		}
		else if (m_pBoard->getFieldStateAt(2, 2) == stone
				&& m_pBoard->getFieldStateAt(1, 1) == 0)
		{
			bestposition.row = 1;
			bestposition.col = 1;
		}
		return true;
	}

	else if (bestDigLeftUp == 3)
	{
		if (m_pBoard->getFieldStateAt(2, 0) == stone
				&& m_pBoard->getFieldStateAt(1, 1) == 0)
		{
			bestposition.row = 1;
			bestposition.col = 1;
		}
		else if (m_pBoard->getFieldStateAt(1, 1) == stone
				&& m_pBoard->getFieldStateAt(0, 2) == 0)
		{
			bestposition.row = 0;
			bestposition.col = 2;
		}
		else if (m_pBoard->getFieldStateAt(0, 2) == stone
				&& m_pBoard->getFieldStateAt(1, 1) == 0)
		{
			bestposition.row = 1;
			bestposition.col = 1;
		}
		return true;
	}

	if (m_pBoard->boardempty() == 4)
	{
		for (unsigned short row = 0; row < 3; row++)
		{
			for (unsigned short col = 0; col < 3; col++)
			{
				if (m_pBoard->getFieldStateAt(row, col) == 0)
				{
					bestposition.row = row;
					bestposition.col = col;
					break;
				}
			}
		}

		return true;
	}

	if (m_pBoard->boardempty() == 3)
	{
		for (unsigned short row = 0; row < 3; row++)
		{
			for (unsigned short col = 0; col < 3; col++)
			{
				if (m_pBoard->getFieldStateAt(row, col) == 0)
				{
					bestposition.row = row;
					bestposition.col = col;
					break;
				}
			}
		}

		return true;
	}

	if (m_pBoard->boardempty() == 2)
	{
		for (unsigned short row = 0; row < 3; row++)
		{
			for (unsigned short col = 0; col < 3; col++)
			{
				if (m_pBoard->getFieldStateAt(row, col) == 0)
				{
					bestposition.row = row;
					bestposition.col = col;
					break;
				}
			}
		}

		return true;
	}

	if (m_pBoard->boardempty() == 1)
	{
		for (unsigned short row = 0; row < 3; row++)
		{
			for (unsigned short col = 0; col < 3; col++)
			{
				if (m_pBoard->getFieldStateAt(row, col) == 0)
				{
					bestposition.row = row;
					bestposition.col = col;
				}
			}
		}

		return true;
	}
	return false;

}
