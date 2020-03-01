#pragma once
#include"action.cpp"
#include<vector>
#include <String>
#include "Game_Field.h"
/*
IO_controller class coordinates the input from the human player.

@var player: 1 or -1 depending who goes first.

public:
				@constr IO_controller: sets player value.
				@func get_Input: takes player input and converts it to an action. Checks if action is legal.
*/
class IO_controller
{
	private:
		int player;

	
	public:
		IO_controller(int pla = -1);
		~IO_controller();

		action get_Input(Game_Field gam);
};

