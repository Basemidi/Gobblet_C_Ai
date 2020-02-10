#pragma once
#include"action.cpp"
#include<vector>
#include <String>
#include "Game_Field.h"

class IO_controller
{
	private:
		int player;

	
	public:
		IO_controller(int pla = -1);
		~IO_controller();

		action get_Input(Game_Field gam);
};

