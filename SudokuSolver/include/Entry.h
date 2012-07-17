#ifndef ENTRY_H
#define ENTRY_H
#include <vector>

class Entry
{
    public:
        Entry(int pvalue, int prow, int pcolumn, int pblock);
        virtual ~Entry();
        Entry(const Entry& other);
        Entry& operator=(const Entry& other);

        int eliminate(int choice);

        const int getRow() { return row; }
        const int getValue() { return value; }
        const int getColumn() { return column; }
        const int getBlock() { return block; }
        std::vector<int> getOptions(){return options;}
        void printOptions();
    protected:
    private:
        int value;
        int row;
        int column;
        int block;
        std::vector<int> options;
};

#endif // ENTRY_H
