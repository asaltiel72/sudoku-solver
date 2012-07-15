#include "../include/Entry.h"

Entry::Entry(int pvalue, int prow, int pcolumn, int pblock)
    : value(pvalue),
    row(prow),
    column(pcolumn),
    block(pblock),
    options(0)
{
    //ctor
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
