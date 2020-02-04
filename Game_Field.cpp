#include "Game_Field.h"
#include <iostream>
#include <String>

Game_Field::Game_Field()
{
}


Game_Field::~Game_Field()
{
}

int Game_Field::getField(int row, int collumn)
{	//TODO: Does this copy the number ?
	return game_fields[row][collumn].back();
}


void Game_Field::setField(action act)
{
	
	int gpiece = game_fields[get<0>(act.location)][get<1>(act.location)].back();
	game_fields[get<0>(act.target)][get<1>(act.target)].push_back(gpiece);

	game_fields[get<0>(act.location)][get<1>(act.location)].pop_back();

}

void Game_Field::setPlayer(int pla)
{
	if (pla == 1) {
		player1 = true;
		player2 = false;
	}
	else {
		player1 = false;
		player2 = true;
	}
}

bool Game_Field::getState()
{
	return gamestate;
}

int Game_Field::whichPlayer()
{
	if (player1) {
		return 1;
	}
	else {
		return -1;
	}
}

vector<action> Game_Field::possibleActions(int play)
{	
	vector <action> act;
	if (play == 1) {
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 3; col++) {
				if (game_fields[row][col].back() > 0) {
					for (int row2 = 1; row2 < 4; row2++) {
						for (int col2 = 0; col2 < 3; col2++) {
							if (abs(game_fields[row][col].back()) > abs(game_fields[row2][col2].back())) {
								action a = action(row, col, row2, col2);
								act.push_back(a);
							}
						}
					}
				}
			}
		}
	}
	else if (play == -1) {
		for (int row = 1; row < 5; row++) {
			for (int col = 0; col < 3; col++) {
				if (game_fields[row][col].back() < 0) {
					for (int row2 = 1; row2 < 4; row2++) {
						for (int col2 = 0; col2 < 3; col2++) {
							if (abs(game_fields[row][col].back()) > abs(game_fields[row2][col2].back())) {
								action a = action(row, col, row2, col2);
								act.push_back(a);
							}
						}
					}
				}
			}
		}
	}
	return act;
}

int Game_Field::checkForWin()
{
	for (int row = 1; row < 4; row++) {

		if (game_fields[row][0].back() > 0 && game_fields[row][1].back() > 0 && game_fields[row][2].back()) {
			return 1;
		}
		else if (game_fields[row][0].back() < 0 && game_fields[row][1].back() < 0 && game_fields[row][2].back()) {
			return -1;
		}
	}

	for (int col = 0; col < 3; col++) {

		if (game_fields[1][col].back() > 0 && game_fields[2][col].back() > 0 && game_fields[3][col].back()) {
			return 1;
		}
		else if (game_fields[1][col].back() < 0 && game_fields[2][col].back() < 0 && game_fields[3][col].back()) {
			return -1;
		}
	}

	if (game_fields[1][0].back() > 0 && game_fields[2][1].back() > 0 && game_fields[3][2].back()) {
		return 1;
	}
	else if (game_fields[1][0].back() < 0 && game_fields[2][1].back() < 0 && game_fields[3][2].back()) {
		return -1;
	}
	else if (game_fields[1][2].back() > 0 && game_fields[2][1].back() > 0 && game_fields[3][0].back()) {
		return 1;
	}
	else if (game_fields[1][2].back() < 0 && game_fields[2][1].back() < 0 && game_fields[3][0].back()) {
		return -1;
	}

	return 0;
}

void Game_Field::printField()
{
	//TODO: Implement printField function.
	std::cout << "Round:" << roundcount << endl;
	std::cout << endl;

	for (int row = 0; row < 5; row++) {
		
		std::cout << "     " << game_fields[row][0].back() << "|" << game_fields[row][1].back() << "|" << game_fields[row][2].back() << endl;

		if (row < 4) {
			std::cout << "   ----------" << endl;
		}
	}
	std::cout << endl;
}

string Game_Field::stateRepresentation()
{

	string stateString;

	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 3; col++) {
			for (int field = 0; field < 3; field++) {
				stateString.append(std::to_string(game_fields[row][col][field]));
			}
		}
	}

	return stateString;
}
