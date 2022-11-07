/*
 * CPosition.cpp
 *
 *      Author: Sayeed Reza Alawi
 */

#include "CPosition.h"

CPosition::CPosition()
{

}

CPosition::~CPosition()
{
	// TODO Auto-generated destructor stub
}
unsigned short CPosition::getRow(unsigned short row)
{
	if (row < 0 || row > m_noRows)
	{
		throw "Wrong Row number selection!";
	}
	return row;
}
unsigned short CPosition::getColumn(unsigned short col)
{
	if (col < 0 || col > m_noColumns)
	{
		throw "Wrong Column number selection!";
	}
	return col;
}
void CPosition::setSize(unsigned short row, unsigned short cols)
{
	m_noRows = row;
	m_noColumns = cols;
}
