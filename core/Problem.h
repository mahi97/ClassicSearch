//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_PROBLEM_H
#define SEARCH_PROJECT_PROBLEM_H

#include "State.h"
#include <vector>
#include <cstring>
#include <list>

class Problem {
public:
	
	// Main funcitons
	virtual ~Problem();
	virtual State* initialState() = 0;
	virtual State* nextState(const State* currentState, const int& action) = 0;
	virtual bool goalTest(const State* _state) = 0;
	virtual double pathCost(std::list<int> path) = 0;
	virtual std::vector<int> actions(const State* _state) = 0;
	virtual double stepCost(const State* firstState, const int& action,const State* secondState) = 0;
	
	// A* additional function
	virtual double h(const State*) = 0;
	
	// Bidirectional additional function
	virtual State* initialStateR() = 0;
	virtual State* nextStateR(const State* currentState, const int& action) = 0;
	virtual bool goalTestBidirect(const State* _state) = 0;

};


#endif //SEARCH_PROJECT_PROBLEM_H
