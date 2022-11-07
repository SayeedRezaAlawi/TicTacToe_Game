// Standard (system) header files
#include <iostream>
#include <stdlib.h>
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
#include "CTicTacToeGame.h"
int CPosition::m_noRows = 0;
int CPosition::m_noColumns = 0;
// Main program
int main (void)
{
    // TODO: Add your program code here
	cout << "TicTacToe_Game started." << endl << endl;
	CTicTacToeGame g;
		g.run();
	return 0;
}
