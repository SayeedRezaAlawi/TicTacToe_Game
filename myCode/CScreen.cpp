/*
 * CScreen.cpp
 *
 *      Author: Sayeed Reza Alawi
 */
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "CScreen.h"

CScreen::CScreen()
{
}

CScreen::~CScreen()
{
}

void CScreen::addElement(CBoard *element)
{
	m_pBoard = element;
}



