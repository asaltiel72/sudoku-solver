#include "../include/Board.h"

Board::Board(std::string filename) :
    orig_file(filename),
    solved(false)
{
    //ctor
    //spot = new Entry[9][9];
}

Board::Board()// : this("board.txt")
{
    //default ctor
}

Board::~Board()
{
    //dtor
}

bool Board::initializeBoard()
{
    //for now
    return true;
}
