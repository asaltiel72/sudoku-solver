#include "../include/Printer.h"
#include <iostream>

using std::cout;
using std::endl;

/** Default Constructor */
Printer::Printer()
{
    //ctor
}

/** Default Destructor */
Printer::~Printer()
{
    //dtor
}

/**
 * Print the top first line of the board
 * using ascii characters.
 */
void Printer::printTop()
{
    // Print the top of the board
    std::cout << TOP_LEFT_CORNER;
    for (int i = 0; i < END_OF_BOARD; i++)
    {
        std::cout << HORIZONTAL_DOUBLE
        << T_SINGLE << HORIZONTAL_DOUBLE
        << T_SINGLE << HORIZONTAL_DOUBLE;
        if (i < END_OF_BOARD - 1)
        {
           std::cout << T_DOUBLE;
        }
    }
    std::cout << TOP_RIGHT_CORNER << std::endl;
}

/**
 * Print a line bookending lines of numbers and pass in
 * whether or not the line is the end of a 3x3
 * block of numbers.
 * @param endOfBlock - true or false (see above)
 */
void Printer::printMiddle(bool pendOfBlock)
{
    if (pendOfBlock)
    {
        std::cout << LEFT_EDGE_DOUBLE;
        for (int i = 0; i < END_OF_BOARD; i++)
        {
            std::cout << HORIZONTAL_DOUBLE << CROSS_HDVS
            << HORIZONTAL_DOUBLE << CROSS_HDVS
            << HORIZONTAL_DOUBLE;
            if (i < END_OF_BOARD - 1)
            {
                std::cout << CROSS_DOUBLE;
            }
        }
        std::cout << RIGHT_EDGE_DOUBLE << std::endl;
    }
    else
    {
        std::cout << LEFT_EDGE_SINGLE;
        for (int i = 0; i < END_OF_BOARD; i++)
        {
            std::cout << HORIZONTAL_SINGLE << CROSS_SINGLE
            << HORIZONTAL_SINGLE << CROSS_SINGLE
            << HORIZONTAL_SINGLE;
            if (i < END_OF_BOARD - 1)
            {
                std::cout << CROSS_HSVD;
            }
        }
        std::cout << RIGHT_EDGE_SINGLE << std::endl;
    }
}

/**
 * Print the bottom line of the board
 * using ascii characters.
 */
void Printer::printBottom()
{
    // Print the bottom of the board
    std::cout << BOTTOM_LEFT_CORNER;
    for (int i = 0; i < END_OF_BOARD; i++)
    {
        std::cout << HORIZONTAL_DOUBLE
        << UDT_SINGLE << HORIZONTAL_DOUBLE
        << UDT_SINGLE << HORIZONTAL_DOUBLE;
        if (i < END_OF_BOARD - 1)
        {
           std::cout << UDT_DOUBLE;
        }
    }
    std::cout << BOTTOM_RIGHT_CORNER << std::endl;
}

/**
 * Print the entire Sudoku board from a Board object.
 * @param pboard - a pointer to a Board object
 */
void Printer::printSudoku(Board* pboard)
{
	std::vector<Entry> cells = pboard->getBoard();

	printTop();

	for(int i = 0; i < 3; i++)
	{
	    for(int j = 0; j < 3; j++)
	    {
            cout << VERTICAL_DOUBLE;
            for(int n = 0; n < 8; n++){
                cout << cells[(3*i+j)*9 + n].getValue();
                if((n + 1) % 3 != 0)
                    cout << VERTICAL_SINGLE;
                else
                    cout << VERTICAL_DOUBLE;
            }
            cout << cells[(3*i+j)*9 + 8].getValue() << VERTICAL_DOUBLE << endl;
            if(j == 2)
            {
                if(i != 2)
                    printMiddle(END_OF_BLOCK);
            }
            else
                printMiddle(!END_OF_BLOCK);
	    }
	}

	printBottom();
}
