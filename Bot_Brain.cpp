#include "Bot_Brain.h"
//This class is used for the artificial Player

Bot_Brain::Bot_Brain(int pla)
{
	player = pla;
}


Bot_Brain::~Bot_Brain()
{
}

int Bot_Brain::getsimucount()
{
	return simulationCount;
}

int Bot_Brain::getrolloutcount()
{
	return rolloutcount;
}

Game_Field Bot_Brain::descent(Game_Field gam)//This should also copy the Object.
{
	Game_Field copygam = gam; //TODO: Is this a copy now?



	return Game_Field();
}

action Bot_Brain::makeRndMove()
{
	action act = action(0, 1, 2, 3);

	return act;
}

action Bot_Brain::think()
{
	action act = action(0, 1, 2, 3);

	return act;
}
