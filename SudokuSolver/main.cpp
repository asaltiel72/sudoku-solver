#include "include/Printer.h"
#include "include/Board.h"

using namespace std;

int main()
{
    Board sudoku("hard.txt");
    sudoku.initializeBoard();
    Printer::printSudoku(&sudoku);
    sudoku.processBoard();
    Printer::printSudoku(&sudoku);
    sudoku.processBoard();
    Printer::printSudoku(&sudoku);
    sudoku.processBoard();
    Printer::printSudoku(&sudoku);
    sudoku.processBoard();
    Printer::printSudoku(&sudoku);
    sudoku.printOptions();
	return 0;
}

