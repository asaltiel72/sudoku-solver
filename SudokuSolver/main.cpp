#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "include/Printer.h"
#include "include/Board.h"

using namespace std;

int main(){
    Printer puzzle;
    Board sudoku("board.txt");
    sudoku.initializeBoard();
    puzzle.printSudoku(&sudoku);
	return 0;
}

