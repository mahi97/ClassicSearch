//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_PROBLEMNAVIGATION_H
#define SEARCH_PROJECT_PROBLEMNAVIGATION_H


#include <Problem.h>

class ProblemNavigation : public Problem {
public:
	virtual State* initialState();
	virtual State* nextState(const State* currentState, const int& action);
	virtual bool goalTest(const State* _state);
	virtual double pathCost(std::vector<int> path);
	virtual std::vector<int> actions(const State* _state);
	virtual double stepCost(State* firstState, const int& action, State* secondState);
	
};


#endif //SEARCH_PROJECT_PROBLEMNAVIGATION_H
