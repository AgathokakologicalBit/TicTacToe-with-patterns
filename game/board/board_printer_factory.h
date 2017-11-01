// Copyright 2017 Ermishin Michael

#pragma once

#include <memory>

#include "board.h"
#include "board_printer.h"


/**
 * [Factory/Builder] for board printer.
 * Adds simple building steps which allows to skip some styles.
 * Build features that were not specified will be set to their default values.
 */
class BoardPrinterFactory {
private:
    std::unique_ptr<BoardPrinter> printer;
    bool is_built;

public:
    /**
     * Creates new board printer builder.
     * @param board_ target board to print
     */
    explicit BoardPrinterFactory(const Board& board_)
        : printer(new BoardPrinter(&board_))
        , is_built(false)
    {}

public:
    /**
     * Sets graphical representation for given cell type
     * @param cell target type
     * @param symbol graphical representation
     * @return self
     */
    BoardPrinterFactory& set_symbol(eCell cell, char symbol) {
        assert(!is_built);

        printer->symbol_table[cell] = symbol;
        return *this;
    }

    /**
     * Creates fully configured board printer
     * @return configured board printer
     */
    BoardPrinter* build()
    {
        assert(!is_built);

        is_built = true;
        auto p = printer.get();
        printer.release();
        return p;
    }
};
