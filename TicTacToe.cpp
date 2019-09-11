// TicTacToe.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "Game.h"
using namespace tkp;

int main() {

	Game game;


	// SETTING THE GAME LOOP

	while (game.getReplay()) {

		//Initialize game
		game.FillTable();

		// Ask to play with IA or with player 2
		cout << "Who are you going to play with: " << endl;
		cout << "1- Alone ( vs Computer)" << endl;
		cout << "2- With another player" << endl;
		if (game.getOption() == 1)
			game.setPlayWithAI(true);

		// Show game field
		game.printTable();

		game.setRandomPlayerTurn();
		while (!game.getGameOver()) {

			if (game.getPlayerTurn() == 2 && game.isPlayingWithAI()) {
				game.setCharacterAI(game.getPlayerTurn());
			}
			else {
				// PLAYER X SELECTS POSITION
				do {
					game.selectPosX();
					game.selectPosY();

				} while (!game.isPosEmpty(game.getPosX(), game.getPosY()));

				game.setCharacter(game.getPlayerTurn(), game.getPosX(), game.getPosY());
			}
			// PRINT TABLE
			game.printTable();

			// CHECK IF LINE
			game.isLine();

			// CHECK IF ARRAY IS FULL
			if (game.isTableFull() && !game.getGameOver()) {
				cout << "Draw!" << endl;
				game.setDraw(true);
				game.setGameOver(true);
			}

			// SELECT PLAYER
			if (!game.getGameOver()) {
				game.setPlayerTurn();
			}
		}

		if (!game.getDraw())
			cout << "Player " << game.getPlayerTurn() << " wins!" << endl;

		cout << "Play again? 1-yes, 2-no" << endl;
		if (game.getOption() == 2) {
			game.setReplay(false);
		}
		else {
			game.setGameOver(false);
			system("cls");
		}
	}
	return 0;
}

