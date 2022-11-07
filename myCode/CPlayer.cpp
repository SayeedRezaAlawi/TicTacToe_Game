/*
 * CPlayer.cpp
 *
 *      Author: Sayeed Reza Alawi
 */

#include "CPlayer.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}
void CPlayer::addBoard(CBoard *element)
{
	m_pBoard = element;
}


