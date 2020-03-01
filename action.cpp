#pragma once
#include <tuple>
#include <vector>
using namespace std;
/*
The action construt represents a game action.
It contains two board positions, location and target.
These positions itself store the row and collumn number of the board position.

@var location: tuple containing row and collumn number.
@var target: tuple containing row and collumn number.

@constr action: creates the Tuples based on the given coordinates.
@oper == : compares the location and target of two actions.
*/
struct action {

	tuple <int, int> location;
	tuple <int, int> target;
	
	action() {

	};

	action(int row1, int coll1, int row2, int coll2) {
		location = make_tuple(row1, coll1);
		target = make_tuple(row2, coll2);
	};

	bool operator==(const action & act1) {

		if (act1.location == location && act1.target == target) {
			return true;
		}
		else {
			return false;
		}
	}
};