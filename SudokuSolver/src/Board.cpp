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


bool Board::processCell(int pr, int pc)
{
    //Search Row
    for(int i = 0; i < rows[pr].size(); i++)
    {
        if(&cells[pr*9 + pc] != &rows[pr][i].get())
        {
            cells[pr*9 + pc].eliminate(rows[pr][i].get().getValue());
            cout << rows[pr][i].get().getValue() << " eliminated from [" << pr << ", " << pc << "]" << endl;
        }
    }

    cout << endl;

    for(int i = 0; i < columns[pc].size(); i++)
    {
        if(&cells[pr*9 + pc] != &columns[pc][i].get())
        {
            cells[pr*9 + pc].eliminate(columns[pc][i].get().getValue());
            cout << columns[pc][i].get().getValue() << " eliminated from [" << pr << ", " << pc << "]" << endl;
        }
    }

    cout << endl;

    int blockNumber = cells[pr*9 + pc].getBlock();
    for(int i = 0; i < blocks[blockNumber].size(); i++)
    {
        if(&cells[pr*9 + pc] != &blocks[blockNumber][i].get())
        {
            cells[pr*9 + pc].eliminate(blocks[blockNumber][i].get().getValue());
            cout << blocks[blockNumber][i].get().getValue() << " eliminated from [" << pr << ", " << pc << "]" << endl;
        }
    }

    return false;
}
