#pragma once
#include <tuple>
#include <vector>
using namespace std;

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