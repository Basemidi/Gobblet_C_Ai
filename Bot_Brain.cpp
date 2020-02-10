#pragma once
#include "Bot_Brain.h"
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <random>
//This class is used for the artificial Player.

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

	return  x + (explore * ro);

}

Game_Field Bot_Brain::descent(Game_Field gam)
{

	path.push_back(gam.stateRepresentation());

	if ((N_value.find(gam.stateRepresentation()) == N_value.end()) || gam.checkForWin() != 0) {
		return gam;
	}

	while(true){
		vector<action> children = gam.possibleActions();
		vector<float> UCB_values;

		for (int num = 0; num < static_cast<int>(children.size()); num++) {
			Game_Field copygam = gam;

			copygam.setField(children[num]);

			if (N_value.find(copygam.stateRepresentation()) == N_value.end()) {
				path.push_back(copygam.stateRepresentation());
				return copygam;
			}
			else {
				if (std::find(path.begin(),path.end(), copygam.stateRepresentation()) == path.end()) {
					UCB_values.push_back(UCB1(copygam));
				}
				
			}
		}
		
		action bestaction = children[distance(UCB_values.begin(), max_element(UCB_values.begin(), UCB_values.end()))];

		gam.setField(bestaction);
		path.push_back(gam.stateRepresentation());

		if (gam.checkForWin() != 0) {
			return gam;
		}
	}
}

void Bot_Brain::expansion(Game_Field gam)
{
	if (N_value.find(gam.stateRepresentation()) != N_value.end()) {
		return;
	}
	else {
		N_value.insert({gam.stateRepresentation() , 0});
		Q_value.insert({gam.stateRepresentation() , 0});
	}

	return;
}

Game_Field Bot_Brain::rollout(Game_Field gam)
{
	if (gam.checkForWin() != 0) {
		return gam;
	}

	std::random_device rd;
	std::mt19937 eng(rd());

	while (gam.checkForWin() == 0) {
		vector<action> children = gam.possibleActions();
		std::uniform_int_distribution<int> distr(0, (static_cast<int>(children.size()) - 1));
		gam.setField(children[distr(eng)]);
	}
	return gam;
}

void Bot_Brain::backPropagation(Game_Field gam)
{
	int pla = player;
	int reward;

	if (gam.checkForWin() == player) {
		reward = 0;
	}
	else {
		reward = 1;
	}

	for (int item = 0; item < static_cast<int>(path.size()); item++) {
		Q_value[path[item]] += reward;
		N_value[path[item]] += 1;

		reward = 1 - reward;
	}
}

action Bot_Brain::makeRndMove(Game_Field gam)
{
	
	std::random_device rd;
	std::mt19937 eng(rd());
	
	vector<action> child = gam.possibleActions();
	std::uniform_int_distribution<> distr(0, (static_cast<int>(child.size()) - 1));

	return child[distr(eng)];
}

action Bot_Brain::think(Game_Field gam)
{
	
	for (int iter = 0; iter < simulationCount; iter++) {

		Game_Field newgam = descent(gam);
		expansion(newgam);

		for (int roll = 0; roll < rolloutcount; roll++) {
			Game_Field donegam = rollout(newgam);
			backPropagation(donegam);
		}
		path.clear();
		std::cout << "Thinking:" << to_string((static_cast<float>(iter) / static_cast<float>(simulationCount)) * 100.0f) << "%" << "\r";
	}

	vector<action> poschild = gam.possibleActions();
	vector<int> Nvals;
	vector<int> Qvalues;

	
	for (int i = 0; i < static_cast<int>(poschild.size()); i++) {
		Game_Field newgam = gam;
		newgam.setField(poschild[i]);

		Nvals.push_back(N_value[newgam.stateRepresentation()]);
		Qvalues.push_back(Q_value[newgam.stateRepresentation()]);

	}

	int maxindex = distance(Nvals.begin(), max_element(Nvals.begin(), Nvals.end()));

	std::cout << to_string((static_cast<float>(Qvalues[maxindex]) / static_cast<float>(Nvals[maxindex]))) << endl;

	return poschild[maxindex];
}

void Bot_Brain::test(Game_Field tes)
{

}
