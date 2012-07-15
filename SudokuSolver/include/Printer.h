#ifndef PRINTER_H
#define PRINTER_H

#include "Board.h";


class Printer
{
    public:
        Printer();
        virtual ~Printer();
        static void printSudoku(Board* pboard);
    protected:
    private:
        static void printTop();
        static void printMiddle(bool endOfBlock);
        static void printBottom();
        static const int END_OF_BOARD = 3;
        static const bool END_OF_BLOCK = 1;
        static const char TOP_LEFT_CORNER = 201;
        static const char TOP_RIGHT_CORNER = 187;
        static const char HORIZONTAL_DOUBLE = 205;
        static const char T_SINGLE = 209;
        static const char T_DOUBLE = 203;
        static const char VERTICAL_DOUBLE = 186;
        static const char VERTICAL_SINGLE = 179;
        static const char LEFT_EDGE_SINGLE = 199;
        static const char LEFT_EDGE_DOUBLE = 204;
        static const char HORIZONTAL_SINGLE = 196;
        static const char CROSS_SINGLE = 197;
        static const char CROSS_HSVD = 215; // Double horizontal lines, single vertical line
        static const char CROSS_HDVS = 216;
        static const char CROSS_DOUBLE = 206;
        static const char RIGHT_EDGE_SINGLE = 182;
        static const char RIGHT_EDGE_DOUBLE = 185;
        static const char BOTTOM_LEFT_CORNER = 200;
        static const char BOTTOM_RIGHT_CORNER = 188;
        static const char UDT_SINGLE = 207;
        static const char UDT_DOUBLE = 202;
};

#endif // PRINTER_H
