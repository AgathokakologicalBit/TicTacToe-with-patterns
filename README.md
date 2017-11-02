# "Tic Tac Toe" with patterns

Simple game implementation using common programming patters.


## Used design patterns

* Builder - for creating `Board` printers with custom settings
* Decorator - `Printers` extends `Boards` functionality (adds ability to print them)
* Interface - `IController` is an abstract class(prototype) which defines game player's turn strategy
* RAII - `Board` manages dynamic memory for storing cells and frees it on destruction
* Singleton - `Game` have a sole instance which runs TicTacToe
* ... - more will be implemented soon


## Screenshots

![Game in progress](https://www.dropbox.com/s/qberq0ybk81vqsm/field_placment_25_5.png?raw=1)
![Game finished](https://www.dropbox.com/s/xpl3612o6ssrs77/field_win_25_5.png?raw=1)


## Do you have a good idea?

Please explain it on the [issues tab](//github.com/mikhail158/tictactoe-with-patterns/issues)

You may also create a pull request assigned to your proposal in order to help make this project better.
