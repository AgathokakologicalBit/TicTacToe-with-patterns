// Copyright 2017 Ermishin Michael

#include <algorithm>
#include <map>
#include <vector>
#include <iostream>

#include "board.h"


bool Board::do_turn(int16_t x, int16_t y) {
    if (x < 0 || x >= size) return false;
    if (y < 0 || y >= size) return false;
    if (this->next_type == eCell::Empty)
        return false;

    // Places X/O on specified cell
    data[y * size + x] = this->next_type;
    // Give turn to the opponent
    this->next_type =
        this->next_type == eCell::X
            ? eCell::O
            : eCell::X;

    return true;
}

eWinner Board::calculate_winner() {
    std::map<eCell, std::map<int16_t, uint16_t>> zones;
    const std::vector<std::pair<int16_t, int16_t>> sides
            { { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 } };

    for (int16_t y = 0; y < size; ++y)
    {
        for (int16_t x = 0; x < size; ++x)
        {
            uint16_t shift = 0;
            // Check valuable neighbor of the cell
            // left, upper left, up, upper right
            for (const auto& side : sides) {
                eCell cell = get(x, y);
                const int16_t nx = x + side.first,
                              ny = y + side.second;

                // Mask target nibble and increment it
                // if neighbor have the same cell type
                const auto mask = static_cast<uint16_t>((1 << (4 * shift)) * 15);
                zones[cell][y * size + x] += 1 << (4 * shift);
                zones[cell][y * size + x] += (cell == get(nx, ny)) * (zones[cell][ny * size + nx] & mask);

                if (((zones[cell][y * size + x] & mask) >> (4 * shift)) >= chain_length)
                {
                    switch (cell)
                    {
                        case eCell::X: return eWinner::X;
                        case eCell::O: return eWinner::O;
                        case eCell::Empty: break;
                    }
                }

                shift += 1;
            }
        }
    }

    return zones.count(eCell::Empty) ? eWinner::NA : eWinner::T;
}
