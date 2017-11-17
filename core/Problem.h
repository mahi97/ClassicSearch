//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_PROBLEM_H
#define SEARCH_PROJECT_PROBLEM_H

#include "State.h"
#include <vector>
#include <cstring>

class Problem {
public:
	virtual ~Problem();
	virtual State* initialState() = 0;
	virtual State* nextState(State* currentState, const int& action) = 0;
	virtual bool goalTest(State* _state) = 0;
	virtual double pathCost(std::vector<int> path) = 0;
	virtual std::vector<int> actions(State* _state) = 0;
	virtual double stepCost(State* firstState, const int& action, State* secondState)= 0;
private:
	std::vector<State> states;
};


#endif //SEARCH_PROJECT_PROBLEM_H
