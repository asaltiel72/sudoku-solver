#include "../include/Board.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;
Board::Board(std::string filename) :
    orig_file(filename),
    solved(false)
{
    //ctor
}

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
    for(int j= 0; j < fline.size(); j++)
    {
        cout << "Vector at " << j << " :" << fline.at(j) << endl;
    }



    return true;
}
