#include "include/Printer.h"
#include "include/Board.h"
#include <iostream>

using namespace std;

int main()
{
    Board sudoku("hard.txt");
    sudoku.initializeBoard();
    Printer::printSudoku(&sudoku);
    cout << sudoku.processBoard() << endl;
    Printer::printSudoku(&sudoku);
    cout << sudoku.processBoard() << endl;
    Printer::printSudoku(&sudoku);
    cout << sudoku.processBoard() << endl;
    Printer::printSudoku(&sudoku);
    cout << sudoku.processBoard() << endl;
    Printer::printSudoku(&sudoku);
	return 0;
}

