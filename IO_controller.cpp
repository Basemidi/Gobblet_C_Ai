#include "IO_controller.h"
#include <string>
#include<iostream>

IO_controller::IO_controller(int pla) {
	player = pla;
}

IO_controller::~IO_controller()
{
}

action IO_controller::get_Input(Game_Field gam)
{
	vector<action> possact = gam.possibleActions();

	int location;
	int target;
	action inp_action;

	while (true) {

		std::cout << "Stone:" << endl;
		std::cin >> location;

		std::cout << "Target:" << endl;
		std::cin >> target;

		if (location/10 == 4 && player == -1) {
			inp_action = action(location/10,
				(location%10 - 1),
				target/10,
				(target%10 - 1));
		}
		else if (location/10 == 4 && player == 1) {
			inp_action = action((location/10 - 4),
				(location%10 - 1),
				target/10,
				(target%10 - 1));
		}
		else {
			inp_action = action(location/10,
				(location%10 - 1),
				target/10,
				(target%10 - 1));
		}

		if (std::find(possact.begin(), possact.end(), inp_action) == possact.end()) {
			std::cout << get<0>(inp_action.location);
			std::cout << get<1>(inp_action.location);
			std::cout << "Not a legal move.";
		}
		else {
			return inp_action;
		}
	}
}
