
#include "pch.h"
#include "Game.h"
#include <time.h>

namespace tkp {

	Game::Game(): posX(0), posY(0), playerTurn(0), gameOver(false),
				  draw(false), playWithAI(false), replay(true){};

	Game::~Game() {};

	void Game::FillTable() {
			for (unsigned int i = 0; i < sizeof(table) / sizeof(table[0]); i++) {
				for (unsigned int j = 0; j < sizeof(table[0]) / sizeof(char); j++) {
					table[i][j] = '-';
				}
			}
		}

	void Game::setRandomPlayerTurn() {
			srand( (unsigned int) time(NULL) ); // initialize random seed;
			int turn = (rand() % 2) + 1;
			if (turn % 2 == 0) {
				playerTurn = 1;
			}
			else {
				playerTurn = 2;
			}

			cout << "Player " << playerTurn << " turn." << endl;
		}

	void Game::setPlayerTurn() {
			if (playerTurn == 1) {
				playerTurn = 2;
			}
			else {
				playerTurn = 1;
			}
			cout << "Player " << playerTurn << " turn." << endl;
		}

	void Game::setCharacter(int player, int posX, int posY) {
			if (player == 1) {
				table[posX][posY] = 'X';
			}
			else
				table[posX][posY] = 'O';

		}
	void Game::setCharacterAI(int player) {
		do {
			setPosX((rand() % 3));
			setPosY((rand() % 3));

		} while (!isPosEmpty(getPosX(), getPosY()));
		setCharacter(player, getPosX(), getPosY());
	}

	void Game::selectPosX() {
			cout << "Select row: " << flush;
			cin >> posX;
			cout << endl;
			setPosX(posX - 1); 
		}

	void Game::selectPosY() {
			cout << "Select column: " << flush;
			cin >> posY;
			cout << endl;
			setPosY(posY - 1);
		}
	int Game::getOption() {
		int o;
		cout << "Select Option: " << flush;
		cin >> o;
		cout << endl;
		return o;
	}

	bool Game::isPosEmpty(int posX, int posY) {
		
			if (table[posX][posY] == '-') {
				return true;
			}
			else {
				if(getPlayerTurn() == 2 && !isPlayingWithAI())
					cout << "Position not available, try again" << endl;
				return false;
			}
		}

	void Game::printTable() {
			for (unsigned int i = 0; i < sizeof(table) / sizeof(table[0]); i++) {
				for (unsigned int j = 0; j < sizeof(table[0]) / sizeof(char); j++) {
					cout << table[i][j] << flush;
				}
				cout << endl;
			}
			cout << endl;
		}

	bool Game::isTableFull() {
			int spacesAvailables = 0;
			for (unsigned int i = 0; i < sizeof(table) / sizeof(table[0]); i++) {
				for (unsigned int j = 0; j < sizeof(table[0]) / sizeof(char); j++) {
					if (table[i][j] == '-')
						spacesAvailables++;
				}
			}

			if (spacesAvailables == 0) {
				return true;
			}
			else {
				return false;
			}
		}

	void Game::isLine() {
			if (checkHorizontal(posX) || checkVertical(posY)
				|| checkDiagonal()) {
				gameOver = true;
			}
			else {
				gameOver = false;
			}
		}

	bool Game::checkHorizontal(int posX) {
			if ((table[posX][0] == 'X' && table[posX][1] == 'X'
				&& table[posX][2] == 'X')
				|| (table[posX][0] == 'O' && table[posX][1] == 'O'
					&& table[posX][2] == 'O')) {
				return true;
			}
			else {
				return false;
			}
		}

	bool Game::checkVertical(int posY) {
			if ((table[0][posY] == 'X' && table[1][posY] == 'X'
				&& table[2][posY] == 'X')
				|| (table[0][posY] == 'O' && table[1][posY] == 'O'
					&& table[2][posY] == 'O')) {
				return true;
			}
			else {
				return false;
			}
		}

	bool Game::checkDiagonal() {
			if (checkBackDiagonal() || checkFrontDiagonal())
				return true;
			else
				return false;
		}

	bool Game::checkBackDiagonal() {
			if ((table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == 'X')

				|| (table[0][0] == 'O' && table[1][1] == 'O' && table[2][2] == 'O')) {
				return true;
			}
			else {
				return false;
			}
		}

	bool Game::checkFrontDiagonal() {
			if ((table[0][2] == 'X' && table[1][1] == 'X' && table[2][0] == 'X')

				|| (table[0][2] == 'O' && table[1][1] == 'O' && table[2][0] == 'O')) {
				return true;
			}
			else {
				return false;
			}
		}


}
