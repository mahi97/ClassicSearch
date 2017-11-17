//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "ProblemPuzzle.h"

State ProblemPuzzle::initialStart() {
	return State();
}

State ProblemPuzzle::nextState(const State &currentState, const int &action) {
	return State();
}

State ProblemPuzzle::goalTest(const State &_state) {
	return State();
}

double ProblemPuzzle::pathCost(std::vector<int> path) {
	return 0;
}

double ProblemPuzzle::stepCost(const State &firstState, const int &action, const State &secondState) {
	return 0;
}
