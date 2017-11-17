//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "ProblemNavigation.h"

State ProblemNavigation::initialStart() {
	return State();
}

State ProblemNavigation::nextState(const State &currentState, const int &action) {
	return State();
}

State ProblemNavigation::goalTest(const State &_state) {
	return State();
}

double ProblemNavigation::pathCost(std::vector<int> path) {
	return 0;
}

double ProblemNavigation::stepCost(const State &firstState, const int &action, const State &secondState) {
	return 0;
}
