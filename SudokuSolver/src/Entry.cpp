#include "../include/Entry.h"

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

void Entry::eliminate(int choice)
{
    for(int i = 0; i <  options.size(); i++)
    {
        if(options[i] == choice)
        {
            options.erase(options.begin() + i);
            break;
        }
    }
}
