/*
 * CBoard.cpp
 *
 *      Author: Sayeed Reza Alawi
 */


#include "CBoard.h"
#include "CPosition.h"
#include <string>
#include <iostream>
using namespace std;

CBoard::CBoard(unsigned short row, unsigned short cols, std::string type)
{
	CPosition::setSize(row,cols);
	m_rows = row;
	m_cols = cols;
	m_Type = type;

	// dynamically create array of pointers of size m_sizex
	m_fields = new field_s*[m_cols];
	// dynamically allocate memory of size m_sizey for each row
	for (int i = 0; i < m_cols; i++)
		m_fields[i] = new field_s[m_rows];
	// assign values to allocated memory
	for (int col = 0; col < m_cols; col++)
	{
		for (int row = 0; row < m_rows; row++)
		{
			m_fields[col][row] = NotOccupied;
		}
	}
}

CBoard::~CBoard()
{
}
void CBoard::setFieldStateAt(unsigned short row, unsigned short col,
		unsigned short stone)
{
	switch (stone)
	{
	case 1:
		m_fields[col][row] = X;
		break;
	case 2:
		m_fields[col][row] = O;
		break;
	}
}

unsigned short CBoard::getFieldStateAt(unsigned short row, unsigned short col)
{
	switch (m_fields[col][row])
	{
	case 0:
		return 0;
		break;
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	}
	return 0;
}

void CBoard::print()
{
	int rows = m_rows;
	int cols = m_cols;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{

			if (m_fields[i][j] == 0)
			{
				cout << " . ";
			}
			else if (m_fields[i][j] == 1)
			{
				cout << " X ";
			}
			else
			{
				cout << " O ";
			}
		}
		cout << endl << endl;
	}
}


