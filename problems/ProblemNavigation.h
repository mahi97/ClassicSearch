//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_PROBLEMNAVIGATION_H
#define SEARCH_PROJECT_PROBLEMNAVIGATION_H


#include <Problem.h>

class ProblemNavigation : public Problem {
public:
	virtual State initialStart();
	virtual State nextState(const State& currentState, const int& action);
	virtual State goalTest(const State& _state);
	virtual double pathCost(std::vector<int> path);
	virtual double stepCost(const State& firstState, const int& action, const State& secondState);
	
};


#endif //SEARCH_PROJECT_PROBLEMNAVIGATION_H
