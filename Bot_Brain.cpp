#pragma once
#include "Bot_Brain.h"
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
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
	float x = (static_cast<float>(Q_value[gamf.stateRepresentation()]) / static_cast<float>(N_value[gamf.stateRepresentation()]));
	float ro = sqrt((log(static_cast<float>(N_value[path.back()])) / static_cast<float>(N_value[gamf.stateRepresentation()])));

	return  x + explore * ro;

}

Game_Field Bot_Brain::descent(Game_Field gam)//This should also copy the Object.
{
	//Game_Field copygam = gam; //TODO: Is this a copy now?


	if ((N_value.find(gam.stateRepresentation()) == N_value.end()) || gam.checkForWin() != 0) {
		return gam;
	}

	path.push_back(gam.stateRepresentation());
	

	while(true){
		vector<action> children = gam.possibleActions();
		vector<float> UCB_values;

		for (int num = 0; num < static_cast<int>(children.size()); num++) {
			Game_Field copygam = gam;
			copygam.setField(children[num]);

			if (N_value.find(copygam.stateRepresentation()) == N_value.end()) {
				return copygam;
			}
			else {
				UCB_values.push_back(UCB1(copygam));
			}
		}

		action bestaction = children[distance(UCB_values.begin(), max_element(UCB_values.begin(), UCB_values.end()))];

		gam.setField(bestaction);
		path.push_back(gam.stateRepresentation());

		if (gam.checkForWin() != 0) {
			return gam;
		}
	}
	return gam;
}

void Bot_Brain::expansion(Game_Field gam)
{
	if (N_value.find(gam.stateRepresentation()) != N_value.end()) {
		return;
	}
	else {
		N_value[gam.stateRepresentation()] = 0;
		Q_value[gam.stateRepresentation()] = 0;
	}

	return;
}

Game_Field Bot_Brain::rollout(Game_Field gam)
{
	while (gam.checkForWin() == 0) {
		vector<action> children = gam.possibleActions();
		gam.setField(children[rand() % children.size()]);
	}
	return gam;
}

void Bot_Brain::backPropagation(Game_Field gam)
{
	int pla = player;
	int reward;

	if (gam.checkForWin() == player) {
		reward = 1;
	}
	else {
		reward = 0;
	}

	for (int item = 0; item < static_cast<int>(path.size()); item++) {
		Q_value[path[item]] += reward;
		N_value[path[item]] += 1;

		reward = 1 - reward;
		pla *= -1;
	}
}

action Bot_Brain::makeRndMove(Game_Field gam)
{
	vector<action> child = gam.possibleActions();


	return child[rand() % child.size()];
}

action Bot_Brain::think(Game_Field gam)
{
	action act = action(0, 1, 2, 3);

	return act;
}
