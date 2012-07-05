#include "../include/Printer.h"
#include <iostream>

Printer::Printer()
{
    //ctor
}

Printer::~Printer()
{
    //dtor
}

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

void Printer::printMiddle(bool endOfBlock)
{
    if (endOfBlock)
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

void Printer::printSudoku()
{
    printTop();

    // Print a row of numbers
    std::cout << VERTICAL_DOUBLE << 1 << VERTICAL_SINGLE << 2 << VERTICAL_SINGLE << 3
    << VERTICAL_DOUBLE << 4 << VERTICAL_SINGLE << 5 << VERTICAL_SINGLE << 6
    << VERTICAL_DOUBLE << 7 << VERTICAL_SINGLE << 8 << VERTICAL_SINGLE << 9
	<< VERTICAL_DOUBLE << std::endl;

    printMiddle(!END_OF_BLOCK);

	// Print a row of numbers
    std::cout << VERTICAL_DOUBLE << 1 << VERTICAL_SINGLE << 2 << VERTICAL_SINGLE << 3
    << VERTICAL_DOUBLE << 4 << VERTICAL_SINGLE << 5 << VERTICAL_SINGLE << 6
    << VERTICAL_DOUBLE << 7 << VERTICAL_SINGLE << 8 << VERTICAL_SINGLE << 9
	<< VERTICAL_DOUBLE << std::endl;

	printMiddle(!END_OF_BLOCK);

	// Print a row of numbers
    std::cout << VERTICAL_DOUBLE << 1 << VERTICAL_SINGLE << 2 << VERTICAL_SINGLE << 3
    << VERTICAL_DOUBLE << 4 << VERTICAL_SINGLE << 5 << VERTICAL_SINGLE << 6
    << VERTICAL_DOUBLE << 7 << VERTICAL_SINGLE << 8 << VERTICAL_SINGLE << 9
	<< VERTICAL_DOUBLE << std::endl;

	printMiddle(END_OF_BLOCK);

	// Print a row of numbers
    std::cout << VERTICAL_DOUBLE << 1 << VERTICAL_SINGLE << 2 << VERTICAL_SINGLE << 3
    << VERTICAL_DOUBLE << 4 << VERTICAL_SINGLE << 5 << VERTICAL_SINGLE << 6
    << VERTICAL_DOUBLE << 7 << VERTICAL_SINGLE << 8 << VERTICAL_SINGLE << 9
	<< VERTICAL_DOUBLE << std::endl;

	printMiddle(!END_OF_BLOCK);

	// Print a row of numbers
    std::cout << VERTICAL_DOUBLE << 1 << VERTICAL_SINGLE << 2 << VERTICAL_SINGLE << 3
    << VERTICAL_DOUBLE << 4 << VERTICAL_SINGLE << 5 << VERTICAL_SINGLE << 6
    << VERTICAL_DOUBLE << 7 << VERTICAL_SINGLE << 8 << VERTICAL_SINGLE << 9
	<< VERTICAL_DOUBLE << std::endl;

	printMiddle(!END_OF_BLOCK);

	// Print a row of numbers
    std::cout << VERTICAL_DOUBLE << 1 << VERTICAL_SINGLE << 2 << VERTICAL_SINGLE << 3
    << VERTICAL_DOUBLE << 4 << VERTICAL_SINGLE << 5 << VERTICAL_SINGLE << 6
    << VERTICAL_DOUBLE << 7 << VERTICAL_SINGLE << 8 << VERTICAL_SINGLE << 9
	<< VERTICAL_DOUBLE << std::endl;

	printMiddle(END_OF_BLOCK);

	// Print a row of numbers
    std::cout << VERTICAL_DOUBLE << 1 << VERTICAL_SINGLE << 2 << VERTICAL_SINGLE << 3
    << VERTICAL_DOUBLE << 4 << VERTICAL_SINGLE << 5 << VERTICAL_SINGLE << 6
    << VERTICAL_DOUBLE << 7 << VERTICAL_SINGLE << 8 << VERTICAL_SINGLE << 9
	<< VERTICAL_DOUBLE << std::endl;

	printMiddle(!END_OF_BLOCK);

	// Print a row of numbers
    std::cout << VERTICAL_DOUBLE << 1 << VERTICAL_SINGLE << 2 << VERTICAL_SINGLE << 3
    << VERTICAL_DOUBLE << 4 << VERTICAL_SINGLE << 5 << VERTICAL_SINGLE << 6
    << VERTICAL_DOUBLE << 7 << VERTICAL_SINGLE << 8 << VERTICAL_SINGLE << 9
	<< VERTICAL_DOUBLE << std::endl;

	printMiddle(!END_OF_BLOCK);

	// Print a row of numbers
    std::cout << VERTICAL_DOUBLE << 1 << VERTICAL_SINGLE << 2 << VERTICAL_SINGLE << 3
    << VERTICAL_DOUBLE << 4 << VERTICAL_SINGLE << 5 << VERTICAL_SINGLE << 6
    << VERTICAL_DOUBLE << 7 << VERTICAL_SINGLE << 8 << VERTICAL_SINGLE << 9
	<< VERTICAL_DOUBLE << std::endl;

	printBottom();
}
