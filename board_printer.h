#pragma once

#include <map>
#include <ostream>

#include "board.h"


class BoardPrinterFactory;

/**
 * [Decorator] for board class. Adds field drawing support with customizable styles
 */
class BoardPrinter {
private:
    Board const * const board; // Reference to the board that should be decorated(made printable)

    std::map<eCell, char> symbol_table; // Styles(Symbolic representation) for game cells

public:
    explicit BoardPrinter(Board const * const board_)
        : board(board_)
    {
        symbol_table[eCell::Empty] = ' ';
        symbol_table[eCell::X] = 'X';
        symbol_table[eCell::O] = 'O';
    }

public:
    /**
     * Gets graphical(symbolic) representation of given cell type
     * @param type target cell type
     * @return character representation of cell type
     */
    char get_symbol(eCell type) const
    {
        return symbol_table.at(type);
    }

    // Allow BoardPrinterFactory to access private fields
    // in order to make indirect class initialization possible
    friend class BoardPrinterFactory;
    // Allow printing board into specified output stream
    friend std::ostream& operator <<(std::ostream& out, const BoardPrinter& p);
};
