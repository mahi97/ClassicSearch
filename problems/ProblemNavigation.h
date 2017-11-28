//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_PROBLEMNAVIGATION_H
#define SEARCH_PROJECT_PROBLEMNAVIGATION_H


#include <Problem.h>

enum NavigationAction {
	MOVE_UP = 0,
	MOVE_DOWN = 3,
	MOVE_LEFT = 2,
	MOVE_RIGHT = 1
};

class NavigationState : public State {
public:
	NavigationState(int x, int y) : x(x), y(y){
		
	}
	virtual bool operator==(const State& _other) const {
		return x == dynamic_cast<const NavigationState&>(_other).x
				&& y == dynamic_cast<const NavigationState&>(_other).y;
	}
	int x,y;
};

class ProblemNavigation : public Problem {
public:
	ProblemNavigation(int n, int m, ...);
	virtual State* initialState();
	virtual State* initialStateR();
	virtual State* nextState(const State* currentState, const int& action);
	virtual State* nextStateR(const State* currentState, const int& action);
	virtual bool goalTest(const State* _state);
	virtual bool goalTestBidirect(const State* _state);
	virtual double pathCost(std::list<int> path);
	virtual std::vector<int> actions(const State* _state);
	virtual double stepCost(const State* firstState, const int& action,const  State* secondState);
	virtual double h(const State*);

private:
	int** field;
	int n,m;
	bool** seen[2];
};


#endif //SEARCH_PROJECT_PROBLEMNAVIGATION_H
