//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_SEARCH_H
#define SEARCH_PROJECT_SEARCH_H


#include "Problem.h"

struct Result {
	int nodeSeen;
	int nodeExpand;
	std::vector<int> path;
	double pathCost;
	int maxMemoryUsage;
	double time;
	State* answer;
	
	
};

class Search {
public:
	Search(bool isGraph);
	virtual ~Search();
	void setProblem(Problem* _problem);
	virtual void execute() = 0;
	Result result;
protected:
	Problem* problem;
	bool isGraph;
	std::vector<State*> openedList;
	std::vector<State*> closedList;

	virtual void search() = 0;
	
};


#endif //SEARCH_PROJECT_SEARCH_H
