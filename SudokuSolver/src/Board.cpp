#include "../include/Board.h"
#include "../include/Entry.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <typeinfo>

using namespace std;
Board::Board(std::string filename) :
    orig_file(filename),
    solved(false),
    rows(9),
    columns(9),
    blocks(9)
{
    //ctor
}

/** Default Destructor */
Board::~Board()
{
    //dtor
}

bool Board::initializeBoard()
{
    fstream filestr (orig_file.c_str(), fstream::in | fstream::out);
    string line;
    vector<int> fline;
    stringstream ss;
    int num;
    while (filestr.good())
    {
        getline(filestr, line);
        cout << line << endl;
        if (line != "")
        {
            for(int i = 0; i < 9; i++)
            {
                ss << line.substr(0,1);
                ss >> num;
                fline.push_back(num);
                ss.clear();
                line.erase(line.begin());
                if (line.length() > 1)
                {
                    line.erase(line.begin());
                }
            }
        }
    }

    for(int r = 0; r < 9; r++)
    {
        for(int c = 0; c < 9; c++)
        {
            int blockNum = ((r/3)*3+(c/3));
            Entry tmp(fline[c+r*9], r, c, blockNum);
            cells.push_back(tmp);
        }
    }

    for_each(cells.begin(), cells.end(), [&](Entry& spot){
        rows[spot.getRow()].push_back(spot);
        columns[spot.getColumn()].push_back(spot);
        blocks[spot.getBlock()].push_back(spot);
    });

    //cout << "All vectors and reference vectors created!!" << endl;

    return true;
}

int Board::processBoard()
{
    int num_changed = 0;
    for_each(cells.begin(), cells.end(), [&](Entry& x){num_changed += eliminate(x);});
    return num_changed;
}

void Board::printOptions()
{
    for_each(cells.begin(), cells.end(), [](Entry& x){x.printOptions();});
}

int Board::eliminate(Entry& entry)
{
    int chg_cnt = 0;
    for_each(rows[entry.getRow()].begin(), rows[entry.getRow()].end(), [&](Entry& s){chg_cnt += s.eliminate(entry.getValue());});
    for_each(columns[entry.getColumn()].begin(), columns[entry.getColumn()].end(), [&](Entry& s){chg_cnt += s.eliminate(entry.getValue());});
    for_each(blocks[entry.getBlock()].begin(), blocks[entry.getBlock()].end(), [&](Entry& s){chg_cnt += s.eliminate(entry.getValue());});
    return chg_cnt;
}
