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
    //Board sudoku("hard.txt");
    //sudoku.initializeBoard();
    //Board copy = sudoku;
    //int runs = 0;
    //while(sudoku.processBoard() > 0){
    //    runs++;
    //}
    //cout << "Starting Board" << endl;
    //Printer::printSudoku(&copy);
    //if(sudoku.isSolved())
    //{
    //    cout << "Solution (" << runs << " runs):" << endl;
    //} else {
    //    cout << "Processed Board (as far as I could go..." << runs << " runs)" << endl;
    //}
    //Printer::printSudoku(&sudoku);
    //sudoku.printOptions();
    Board sudoku("hard.txt");
    sudoku.initializeBoard();
    //sudoku.processBoard();
    //sudoku.processBoard();
    //sudoku.printOptions();
    //Printer::printSudoku(&sudoku);
    //sudoku.guess(0);
    //Printer::printSudoku(&sudoku);
    solve(sudoku);
    Printer::printSudoku(&sudoku);
    //sudoku.printOptions();
    //cout << boolalpha << sudoku.canBeSolved();
	return 0;
}

