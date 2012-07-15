#include "include/Printer.h"
#include "include/Board.h"

using namespace std;

int main()
{
    Board sudoku("board.txt");
    sudoku.initializeBoard();
    Printer::printSudoku(&sudoku);
	return 0;
}

