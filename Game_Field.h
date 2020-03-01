#pragma once
#include"action.cpp"
#include<vector>
#include <String>
/*
The Game_Field class represents the game field. 
It contains the current state of the game and the possible actions.
It also provides means to render the field to console.

@var game_fields: An array containing vectors of fields. First and last are the unplayed game tokens.
@var roundcount: stores the number of times a move haas been made.
@var player1: true when player 1 has to make his move.
@var player2: true when player 2 has to make his move.
@var gamestate: true as long as the game is not over.

private:
				@func setPlayer: When a move hast been made this funtion sets the new ative player.

public:
				@constr Game_Field: creates a new game field.
				@func getField: takes row and collumn number and returns the value of the field.
				@func setField: takes an action and relocates the game tokens.
				@func getState: returns true if the game is running.
				@func whichPlayer: returns either 1 or -1 depending on which player is currently active.
				@func possibleActions: returns a vector of all possible actions for the current active player and the board situation.
				@func checkForWin: returns the player token which has won (1 or -1) or 0 if the game is not over.
				@func printField: renders the game field to console.
				@func stateRepresentation: converts the board into a string representing the board situation to store it as key for the dictionarys of the Bot_Brain Class.

*/
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

