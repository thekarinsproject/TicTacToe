
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

namespace tkp {

	class Game {
	public:
		char table[3][3] =
		{ { 'X', 'X', 'X' }, { 'X', 'X', 'X' }, { 'X', 'X', 'X' } };
	public:
		Game();
		~Game();
		void setGameOver(bool game) { gameOver = game; };
		bool getGameOver() { return gameOver; };
		int getPlayerTurn() { return playerTurn; };
		int getPosX() { return posX; };
		void setPosX(int px) { posX = px; };
		int getPosY() { return posY; };
		void setPosY(int py) { posY = py; };
		void setPlayWithAI(bool p) { playWithAI = p; };
		bool isPlayingWithAI() { return playWithAI; };
		bool getDraw() { return draw; };
		void setDraw(bool d) { draw = d; };
		void FillTable();
		void setRandomPlayerTurn();
		void setPlayerTurn();
		void setCharacter(int player, int posX, int posY);
		void setCharacterAI(int player);
		int getOption();
		void selectPosX();
		void selectPosY();
		bool isPosEmpty(int posX, int posY);
		void printTable();
		bool isTableFull();
		void isLine();
		bool checkHorizontal(int posX);
		bool checkVertical(int posY);
		bool checkDiagonal();
		bool checkBackDiagonal();
		bool checkFrontDiagonal();
		bool getReplay() { return replay; };
		void setReplay(bool r) { replay = r; };

	private:
		int posX, posY, playerTurn;
		bool gameOver = false;
		bool draw = false;
		bool playWithAI = false;
		bool replay = false;
	};
}
