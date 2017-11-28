//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_PROBLEMWATER_H
#define SEARCH_PROJECT_PROBLEMWATER_H


#include <Problem.h>

enum WaterAction {
	FILL_0  = 0,
	FILL_1  = 1,
	MOVE_0  = 2,
	MOVE_1  = 3,
	EMPTY_0 = 4,
	EMPTY_1 = 5
};

class WaterState : public State {
public:
	WaterState(int b0, int b1) : bottle{b0, b1} {
		
	}
	virtual bool operator==(const State& _other) const {
		return bottle[0] == dynamic_cast<const WaterState&>(_other).bottle[0]
				&& bottle[1] == dynamic_cast<const WaterState&>(_other).bottle[1];
	}
	const int maxsize[2]{3, 4};
	int bottle[2]{0, 0};
private:
};

class ProblemWater : public Problem {
public:
	virtual State* initialState();
	virtual State* initialStateR();
	virtual State* nextState(const State* currentState, const int& action);
	virtual State* nextStateR(const State* currentState, const int& action);
	virtual bool goalTest(const State* _state);
	virtual bool goalTestBidirect(const State* _state);
	virtual double pathCost(std::list<int> path);
	virtual std::vector<int> actions(const State* _state);
	virtual double stepCost(const State* firstState, const int& action,const State* secondState);
	virtual double h(const State*) {return 0.0;};
};


#endif //SEARCH_PROJECT_PROBLEMWATER_H
