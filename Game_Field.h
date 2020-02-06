#pragma once
#include"action.cpp"
#include<vector>
#include <String>

class Game_Field
{
	private:
		vector<int> game_fields[5][3] = {{{0,1,1},{0,2,2},{0,3,3}},
										{{0},{0},{0}},
										{{0},{0},{0}},
										{{0},{0},{0}},
										{{0,-1,-1},{0,-2,-2},{0,-3,-3}} };
		int roundcount = 0;
		bool player1 = true;
		bool player2 = false;
		bool gamestate = true;
		void setPlayer();

	public:
		Game_Field();
		~Game_Field();

		int getField(int row, int collumn);
		void setField(action act);
		bool getState();
		int whichPlayer();

		vector<action> possibleActions();
		int checkForWin();
		void printField();
		std::string stateRepresentation();
};

