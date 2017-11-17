//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_PROBLEMWATER_H
#define SEARCH_PROJECT_PROBLEMWATER_H


#include <Problem.h>

class ProblemWater : public Problem {
public:
	virtual State* initialState();
	virtual State* nextState(State* currentState, const int& action);
	virtual bool goalTest(State* _state);
	virtual double pathCost(std::vector<int> path);
	virtual std::vector<int> actions(State* _state);
	virtual double stepCost(State* firstState, const int& action, State* secondState);
	
};


#endif //SEARCH_PROJECT_PROBLEMWATER_H
