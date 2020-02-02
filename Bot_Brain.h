
#pragma once
#include <vector>
#include "action.cpp"
using namespace std;

class Bot_Brain
{	private:
		int simulationCount = 50000;
		int rolloutcount = 10;
		int player;

	public:
		Bot_Brain(int pla = 1);
		~Bot_Brain();

		int getsimucount();
		int getrolloutcount();

		action makeRndMove();
		action think();


};

