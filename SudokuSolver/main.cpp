#include "include/Printer.h"
#include "include/Board.h"
#include <iostream>

using namespace std;

int main()
{
    Board sudoku("hard.txt");
    sudoku.initializeBoard();
    Board copy = sudoku;
    Printer::printSudoku(&sudoku);
    cout << sudoku.processBoard() << endl;
    Printer::printSudoku(&sudoku);
    cout << sudoku.processBoard() << endl;
    Printer::printSudoku(&sudoku);
    cout << sudoku.processBoard() << endl;
    Printer::printSudoku(&sudoku);
    //sudoku.setValue(0,5,4);
    cout << sudoku.processBoard() << endl;
    Printer::printSudoku(&sudoku);
    cout << sudoku.processBoard() << endl;
    Printer::printSudoku(&sudoku);
    cout << sudoku.processBoard() << endl;
    Printer::printSudoku(&sudoku);
    cout << sudoku.processBoard() << endl;
    Printer::printSudoku(&sudoku);
    Printer::printSudoku(&copy);
	return 0;
}

