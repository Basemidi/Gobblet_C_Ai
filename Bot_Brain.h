
#pragma once
#include <vector>
#include <map>
#include <string>
#include "action.cpp"
#include "Game_Field.h"
using namespace std;

class Bot_Brain
{	private:
		int simulationCount = 50000;
		int rolloutcount = 10;
		float explore = 0.5;
		vector<string> path;
		int player;

		std::map<string, int> Q_value;
		std::map<string, int> N_value;

		int getsimucount();
		int getrolloutcount();
		float UCB1(Game_Field gamf);

		Game_Field descent(Game_Field gam);


	public:
		Bot_Brain(int pla = 1);
		~Bot_Brain();

		action makeRndMove();
		action think();


};

