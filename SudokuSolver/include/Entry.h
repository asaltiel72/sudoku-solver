#ifndef ENTRY_H
#define ENTRY_H
#include <vector>

class Entry
{
    public:
        Entry(int value, int row, int column, int block);
        virtual ~Entry();
        Entry(const Entry& other);
        Entry& operator=(const Entry& other);
    protected:
    private:
        int value;
        int row;
        int column;
        int block;
        std::vector<int> options;
};

#endif // ENTRY_H
