// Copyright 2017 Ermishin Michael

#pragma once

#include <memory>

#include "board/board.h"
#include "board/board_printer.h"
#include "../controllers/controller.h"

#include "../input/console.cpp"
#include "../controllers/user_controller.h"
#include "../input/input_manager.h"


/**
 * [Singleton] 'Tic Tac Toe' game manager
 */
class Game {
public:
    // Singletons can not be created or assigned
    Game(const Game&) = delete;
    Game& operator =(const Game&) = delete;

public:
    /**
     * Sole instance getter
     * @return singleton instance
     */
    static Game& get()
    {
        // Static variable initializes only on first access
        static Game game;
        return game;
    }


private:
    std::unique_ptr<Board> _board;
    std::unique_ptr<BoardPrinter> _printer;
    eWinner _winner;

    Console* input;

    std::unique_ptr<IController> _player1;
    std::unique_ptr<IController> _player2;

private:
    Game()
        : _board()
        , _printer()
        , _winner(eWinner::NA)
        , input(InputManager::get().console())
        , _player1(std::make_unique<UserController>())
        , _player2(std::make_unique<UserController>())
    {}

    ~Game() = default;

public:
    /**
     * Performs game initialization and board configuration.
     * Reads information from input.
     */
    void init();
    /**
     * Runs 1 game turn and returns updated state.
     *   true - game is running
     *   false - game is finished (no more empty cells / one of players has won)
     * @return new game state
     */
    bool update();
    /**
     * Draws board using printer with styling
     */
    void render();

    /**
     * Returns
     *   eWinner:NA - if game wasn't finished
     *   eWinner:T - if no there are no more empty cells
     * @return game winner
     */
    const eWinner winner() { return _winner; }
    /**
     * Gets graphical representation of winner's symbol
     * @return printable character
     */
    const char winner_symbol() { return _printer->get_symbol(_winner == eWinner::X ? eCell::X : eCell::O); }

    /**
     * @return Currently going player
     */
    const eCell current() { return _board->get_current_player(); }

    /**
     * @return Currently going player's symbol
     */
    const char current_symbol() { return _printer->get_symbol(current()); }
};
