#include "include/Printer.h"
#include "include/Board.h"
#include <iostream>

using namespace std;

int main()
{
    Board sudoku("hard.txt");
    sudoku.initializeBoard();
    Board copy = sudoku;
    int runs = 0;
    while(sudoku.processBoard() > 0){
        runs++;
    }
    cout << "Starting Board" << endl;
    Printer::printSudoku(&copy);
    if(sudoku.isSolved())
    {
        cout << "Solution (" << runs << " runs):" << endl;
    } else {
        cout << "Processed Board (as far as I could go..." << runs << " runs)" << endl;
    }
    Printer::printSudoku(&sudoku);
    //sudoku.printOptions();
	return 0;
}

