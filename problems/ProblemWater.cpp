//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "ProblemWater.h"

State ProblemWater::initialStart() {
	return State();
}

State ProblemWater::nextState(const State &currentState, const int &action) {
	return State();
}

State ProblemWater::goalTest(const State &_state) {
	return State();
}

double ProblemWater::pathCost(std::vector<int> path) {
	return 0;
}

double ProblemWater::stepCost(const State &firstState, const int &action, const State &secondState) {
	return 0;
}
