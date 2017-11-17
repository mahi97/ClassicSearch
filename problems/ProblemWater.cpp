//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "ProblemWater.h"

State* ProblemWater::initialState() {
	return nullptr;
}

State* ProblemWater::nextState(State *currentState, const int &action) {
	return nullptr;
}

bool ProblemWater::goalTest(State *_state) {
	return false;
}

double ProblemWater::pathCost(std::vector<int> path) {
	return 0;
}

double ProblemWater::stepCost(State *firstState, const int &action, State *secondState) {
	return 0;
}

std::vector<int> ProblemWater::actions(State *_state) {
	return std::vector<int, std::allocator<int>>();
}
