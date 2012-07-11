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
    puzzle.printSudoku();
    Board sudoku("board.txt");
    sudoku.initializeBoard("board.txt");
	return 0;
}

