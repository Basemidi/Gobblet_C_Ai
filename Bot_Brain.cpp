#pragma once
#include "Bot_Brain.h"
#include <vector>
#include <map>
#include <string>
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

float Bot_Brain::UCB1(Game_Field gamf)
{
	float x = (Q_value[gamf.stateRepresentation()] / N_value[gamf.stateRepresentation()]);
	float ro = sqrt((log(N_value[path.back()]) / N_value[gamf.stateRepresentation()]));

	return  x + explore * ro;

}

Game_Field Bot_Brain::descent(Game_Field gam)//This should also copy the Object.
{
	//Game_Field copygam = gam; //TODO: Is this a copy now?


	if (N_value.find(gam.stateRepresentation()) == N_value.end()) {
		return gam;
	}

	while(true){
		vector<action> children = gam.possibleActions(player);
		vector<float> UCB_values;

		for (int num = 0; num < children.size(); num++) {
			Game_Field copygam = gam;
			copygam.setField(children[num]);

			if (N_value.find(copygam.stateRepresentation()) == N_value.end()) {
				return copygam;
			}
			else {

			}

		}

	}


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
