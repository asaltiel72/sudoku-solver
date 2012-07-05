#include "../include/Entry.h"

Entry::Entry(int value, int row, int column, int block)
    : value(value),
    row(row),
    column(column),
    block(block),
    options(0)
{
    //ctor
}

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
