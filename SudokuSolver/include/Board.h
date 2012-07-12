#ifndef BOARD_H
#define BOARD_H

#include "Entry.h"
#include <string>
#include <vector>
#include <memory>
#include <math.h>
#include <algorithm>

class Board
{
    public:
        Board();
        Board(std::string filename);
        virtual ~Board();
        bool initializeBoard();

        std::string& getOrigFile() { return orig_file; }
        bool isSolved() { return solved; }
        std::vector<Entry> getBoard() { return cells; }

    protected:
    private:
        std::string orig_file;
        bool solved;
        std::vector<Entry> cells;
        std::vector<std::vector<std::reference_wrapper<Entry>>> rows;      //# = row
        std::vector<std::vector<std::reference_wrapper<Entry>>> columns;   //# = col
        std::vector<std::vector<std::reference_wrapper<Entry>>> blocks;    //# = (col/3)*3 + (row/3)*3
};

#endif // BOARD_H
