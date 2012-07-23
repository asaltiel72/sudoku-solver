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

int Board::processSector(vector<vector<reference_wrapper<Entry>>> sector)
{
    vector<int> test = {0,0,0,0,0,0,0,0,0,0};
    vector<int> temp;
    int position = 0;
    int rvalue = 0;
    int k;
    while(position < 9)
    {
        temp = test;
        for_each(sector[position].begin(), sector[position].end(), [&temp](Entry& x)
                 {
                     if(x.getOptions().size() != 0){for(int q = 0; q < x.getOptions().size(); q++){temp[x.getOptions().at(q) - 1]++;}}
                 });
        for(int j = 0; j < temp.size(); j++)
        {
            if(temp.at(j) == 1)
            {
                k = j + 1;
            }
        }
        if (k != 0)
        {
            for_each(sector[position].begin(), sector[position].end(), [&](Entry& z){if(z.contains(k))
                     {z.setValue(k);
                        rvalue += eliminate(z);}});
            k = 0;
        }
        position++;
    }
    return rvalue;
}

int Board::processBoard()
{
    int num_changed = 0;
    for_each(cells.begin(), cells.end(), [&](Entry& x){num_changed += eliminate(x);});
    if (num_changed == 0)
    {
        num_changed += processSector(rows);
        num_changed += processSector(columns);
        num_changed += processSector(blocks);
    }
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

bool Board::checkBoard()
{
    if(!checkSector(rows) || !checkSector(columns) || !checkSector(blocks))
    {
        return false;
    }
    return true;
}

bool Board::checkSector(vector<vector<reference_wrapper<Entry>>> sector)
{
    vector<int> checkVector(9,0);
    vector<int> temp;
    for (int i = 0; i < sector.size(); i++)
    {
        temp = checkVector;
        for_each(sector[i].begin(), sector[i].end(), [&temp](Entry& cell){temp[cell.getValue()]+= 1;});
        for(int j = 0; j < temp.size(); j++)
        {
            if(temp.at(j) != 1)
            {
                return false;
            }
        }
    }
    return true;
}

void Board::setValue(int row, int column, int value)
{
    cells[(row*9) + column].setValue(value);
}
