#ifndef BOARD_H
#define BOARD_H

#include "Entry.h"
#include <string>

class Board
{
    public:
        Board();
        Board(string filename);
        virtual ~Board();
        bool initializeBoard();

        Entry& getSpot(int x, int y) { return spot[y][x]; };
        string& getOrigFile() { return orig_file; }
        bool isSolved() { return solved; }

    protected:
    private:
        Entry spot[][];
        string orig_file;
        bool solved;
};

#endif // BOARD_H
