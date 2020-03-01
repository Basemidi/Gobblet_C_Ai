
#pragma once
#include <vector>
#include <map>
#include <string>
#include "action.cpp"
#include "Game_Field.h"
using namespace std;

/*
This class is the main part of the AI.
It uses a version of Monte Carlo Tree search
to find the best action given a game state.

@var simulationCount: The number of states which are explored.
@var rolloutcount: The number of rollouts performed for each newly added state.
@var explore: The exploration rate of the search process.
@var path: Contains every visited state during one iteration of the search.
@var player: 1 if the AI goes first -1 if it goes second.
@var Q_values: Dictionary wich stores the number of wins in the rollout process for each state.
@var N_values: The number of times a state has been visited.

private:
			@func UCB1: UCB1 takes a game object and calculates the ucb value.
			@func descent: This method returns a newly found state after traversing the gametree.
			@func expand: This method adds a gamestate to the Q and N values.
			@func rollout: Plays the game with random moves from a given gamestate.
			@func backPropagation: propagates the results of the rollout along the path.

public:
			@func makeRndMove: returns a random action given a gamestate.
			@func think: Given a gamestate it returns the best action based on its estimation.
*/

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
		void expansion(Game_Field gam);
		Game_Field rollout(Game_Field gam);
		void backPropagation(Game_Field gam);

	public:
		Bot_Brain(int pla = 1);
		~Bot_Brain();

		action makeRndMove(Game_Field gam);
		action think(Game_Field gam);

		void test(Game_Field tes);
};

