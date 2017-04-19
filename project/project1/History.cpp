///////////////////////////////////////////////////////////////////////////
//  History implementation
///////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
#include "History.h"

History::History(int nRow, int nCols){
	m_rows = nRow;
	m_cols = nCols;

	// Init grid
	for (int i = 0; i < m_rows; ++i)
		for (int j = 0; j < m_cols; ++j)
			m_grid[i][j] = 0;
}

void History::display() const
{
	char displayGrid[m_rows][m_cols];
    for (int r = 0; r < m_rows; r++)
        for (int c = 0; c < m_cols; c++)
            displayGrid[r][c] = (m_grid[r][c] == 0 ? '.' : (char)(m_grid[r][c]+64));

// Draw the grid
    clearScreen();
    for (int r = 0; r < m_rows; r++)
    {
        for (int c = 0; c < m_cols; c++)
            cout << displayGrid[r][c];
        cout << endl;
    }
    cout << endl;
}

bool History::record(int r,int c)
{
	if (r>0 && c>0 && r<= m_rows && c <= m_cols){
		if (m_grid[r-1][c-1] >=26){
			m_grid[r-1][c-1] = 26;
		} 
		else{
			m_grid[r-1][c-1]++;
		}
		return true;
	}
	return false;	
}