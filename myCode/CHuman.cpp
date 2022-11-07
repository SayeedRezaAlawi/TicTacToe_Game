/*
 * CHuman.cpp
 *
 *      Author: Sayeed Reza Alawi
 */

#include "CHuman.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

CHuman::CHuman() :
		CPlayer()
{
}

CHuman::~CHuman()
{
}

bool CHuman::placeStone(unsigned short stone)
{
	unsigned short inputstatus = 0;
	unsigned short row = 0;
	unsigned short rowinputcheck = 0;
	while (inputstatus == 0)
	{
		while (rowinputcheck == 0)
		{
			try
			{
				cout << "Please enter the Row number from 1 to 3: ";
				cin >> row;
				if (row < 1)
				{
					throw row;
				}
				else if (row > 3)
				{
					throw row;
				}
				m_inputRowPosition = row;
				rowinputcheck = 1;
			} catch (unsigned short row)
			{
				cout << "Wrong Row number is entered please try again. " << endl
						<< endl;
			}
		}

		unsigned short col = 0;
		unsigned short colinputcheck = 0;
		while (colinputcheck == 0)
		{
			try
			{
				cout << "Please enter the Columns number from 1 to 3: ";
				cin >> col;
				if (col < 1)
				{
					throw col;
				}
				else if (col > 3)
				{
					throw col;
				}
				m_inputColPosition = col;
				colinputcheck = 1;
			} catch (unsigned short col)
			{
				cout << "Wrong Column number is entered please try again. "
						<< endl << endl;
			}
		}

		unsigned short fieldstate = 0;
		try
		{
			fieldstate = m_pBoard->getFieldStateAt(m_inputColPosition - 1,
					m_inputRowPosition - 1);
			if (fieldstate != 0)
			{
				throw fieldstate;
			}
			m_pBoard->setFieldStateAt(m_inputColPosition - 1,
					m_inputRowPosition - 1, stone);
			inputstatus = 1;
		} catch (unsigned short fieldstate)
		{
			cout
					<< "Entered Place is already occupied, please try with new Row and Column numbers. "
					<< endl << endl;
		}
	}
	return winnerEvaluation(stone);
}

bool CHuman::winnerEvaluation(unsigned short stone)
{

	// Checking Rows winner.
	for (int row = 0; row < 3; row++)
	{
		if (m_pBoard->getFieldStateAt(row, 0)
				== m_pBoard->getFieldStateAt(row, 1)
				&& m_pBoard->getFieldStateAt(row, 1)
						== m_pBoard->getFieldStateAt(row, 2))
		{
			if (m_pBoard->getFieldStateAt(row, 0) == stone)
				return true;
		}
	}
	// Checking Columns winner.
	for (int col = 0; col < 3; col++)
	{
		if (m_pBoard->getFieldStateAt(0, col)
				== m_pBoard->getFieldStateAt(1, col)
				&& m_pBoard->getFieldStateAt(1, col)
						== m_pBoard->getFieldStateAt(2, col))
		{
			if (m_pBoard->getFieldStateAt(0, col) == stone)
				return true;
		}
	}

	// Checking Diagonals winner.
	if (m_pBoard->getFieldStateAt(0, 0) == m_pBoard->getFieldStateAt(1, 1)
			&& m_pBoard->getFieldStateAt(1, 1)
					== m_pBoard->getFieldStateAt(2, 2))
	{
		if (m_pBoard->getFieldStateAt(0, 0) == stone)
			return true;
	}

	if (m_pBoard->getFieldStateAt(0, 2) == m_pBoard->getFieldStateAt(1, 1)
			&& m_pBoard->getFieldStateAt(1, 1)
					== m_pBoard->getFieldStateAt(2, 0))
	{
		if (m_pBoard->getFieldStateAt(0, 2) == stone)
			return true;
	}

	// Else if none of them have won then return 0
	return false;
}

