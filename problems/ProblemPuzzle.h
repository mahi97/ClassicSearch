//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_PROBLEMPUZZLE_H
#define SEARCH_PROJECT_PROBLEMPUZZLE_H


#include <Problem.h>

class ProblemPuzzle : public Problem {
	virtual State initialStart();
	virtual State nextState(const State& currentState, const int& action);
	virtual State goalTest(const State& _state);
	virtual double pathCost(std::vector<int> path);
	virtual double stepCost(const State& firstState, const int& action, const State& secondState);
	
};


#endif //SEARCH_PROJECT_PROBLEMPUZZLE_H
