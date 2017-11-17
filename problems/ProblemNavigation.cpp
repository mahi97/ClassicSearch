//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "ProblemNavigation.h"

State* ProblemNavigation::initialState() {
}

State* ProblemNavigation::nextState(State *currentState, const int &action) {
}

bool ProblemNavigation::goalTest(State *_state) {
}

double ProblemNavigation::pathCost(std::vector<int> path) {
	return 0;
}

double ProblemNavigation::stepCost(State *firstState, const int &action, State* secondState) {
	return 0;
}

std::vector<int> ProblemNavigation::actions(State *_state) {
	
}
