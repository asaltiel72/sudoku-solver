#include "../include/Entry.h"
#include <algorithm>
#include <iostream>
using namespace std;

Entry::Entry(int pvalue, int prow, int pcolumn, int pblock)
    : value(pvalue),
    row(prow),
    column(pcolumn),
    block(pblock)
{
    //ctor
    if(pvalue == 0)
    {
        options = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    } else {
        options = {};
    }
}

/** Default Destructor */
Entry::~Entry()
{
    //dtor
}

Entry::Entry(const Entry& other)
    : value(other.value),
    row(other.row),
    column(other.column),
    block(other.block),
    options(other.options)
{
    //copy ctor
}

Entry& Entry::operator=(const Entry& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

int Entry::eliminate(int choice)
{
    int eliminatedSomething = 0;
    for(int i = 0; i <  options.size(); i++)
    {
        if(options[i] == choice)
        {
            options.erase(options.begin() + i);
            eliminatedSomething++;
            break;
        }
    }
    if(options.size() == 1)
    {
        value = options.at(0);
    }
    return eliminatedSomething;
}

void Entry::printOptions()
{
    cout << "Row:" << row << " Column: " << column << " Options: ";
    for_each(options.begin(), options.end(), [](int x){cout << x;});
    cout << endl;
}
