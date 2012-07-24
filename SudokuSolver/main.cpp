#include "include/Printer.h"
#include "include/Board.h"
#include <iostream>

using namespace std;
bool solve(Board& pboard)
{
    while(!pboard.checkBoard())
    {
        if(!pboard.canBeSolved())
        {
            return false;
        }
        if(pboard.processBoard() == 0)
        {
            Board cboard = pboard;
            pboard.guess(0);
            if(!solve(pboard))
            {
                cboard.guess(1);
                pboard = cboard;
            }
        }
    }
    return true;
}
int main()
{
    Board sudoku("hard.txt");
    sudoku.initializeBoard();
    cout << "Original Sudoku Board:" << endl;
    Printer::printSudoku(&sudoku);
    cout << endl << endl;
    solve(sudoku);
    cout << "Final Board (After Processing):" << endl;
    Printer::printSudoku(&sudoku);
	return 0;
}

