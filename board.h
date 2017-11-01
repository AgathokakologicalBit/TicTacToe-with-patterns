#pragma once

#include <cassert>
#include <cstdint>
#include <vector>

#include "ecell.h"
#include "ewinner.h"


/**
 * Represents TicTacToe board with custom size and target chain length(winning length)
 */
class Board {
public:
    /**
     * Holds board width & height
     */
    std::size_t const size;
    /**
     * Holds game's winning sequence length
     */
    int16_t const chain_length;

private:
    std::vector<eCell> data; // 1D board array
    eCell next_type;    // Next going player (or eCell::Empty if game is finished)

public:
    /**
     * Initializes new board with equal amount of rows & columns.
     * Size must always be greater than chain length
     * @param size_ Board width & height: 3..1024
     * @param chain_length_ Winning chain length: 3..16
     */
    Board(int16_t size_, int16_t chain_length_)
        : size(static_cast<std::size_t>(size_))
        , chain_length(chain_length_)
        , data(size * size, eCell::Empty)
        , next_type(eCell::X)
    {
        assert(2 < chain_length && chain_length < 16);
        assert(size >= chain_length && size < 1024);
    }

    ~Board() = default;

    /**
     * Returns target cell's value
     * @param x target column
     * @param y target row
     * @return Cell's value
     */
    eCell get(int16_t x, int16_t y) const
    {
        if (x < 0 || x >= size) return eCell::Empty;
        if (y < 0 || y >= size) return eCell::Empty;
        return data[y * size + x];
    }

    /**
     * Places next player's symbol into target location
     * Returns true if all of the following conditions are met:
     *   game is not finished
     *   x,y are on board
     *   target location is not occupied
     * @param x target column
     * @param y target row
     * @return placement result (success / error)
     */
    bool do_turn(int16_t x, int16_t y);

    /**
     * Returns:
     *   eCell::X - if 1st(first) player is going
     *   eCell::O - if 2nd(second) player is going
     *   eCell::Empty - if game is finished
     * @return Next player's symbol
     */
    eCell get_current_player()
    {
        return next_type;
    }

    /**
     * Return one of 4(four) values:
     *   eWinner::NA - if game was not finished yet.
     *   eWinner::X  - if 1st(first) player has won
     *   eWinner::O  - if 2nd(second) player has won
     *   eWinner::T  - if game was finished with a tie
     * @return game state
     */
    eWinner get_winner();
};
