#ifndef BOARD_H
#define BOARD_H

#include "Entry.h"
#include <string>

class Board
{
    public:
        Board();
        Board(std::string filename);
        virtual ~Board();
        bool initializeBoard(std::string filename);

//        Entry& getSpot(int x, int y) { return spot[y][x]; };
        std::string& getOrigFile() { return orig_file; }
        bool isSolved() { return solved; }

    protected:
    private:
//        Entry spot[][];
        std::string orig_file;
        bool solved;
};

#endif // BOARD_H
