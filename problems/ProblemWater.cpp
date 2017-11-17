//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "ProblemWater.h"

State* ProblemWater::initialState() {
	return new WaterState();
}

State* ProblemWater::nextState(const State *currentState, const int &action) {
	WaterState* next = new WaterState();
	next->bottle[0] = reinterpret_cast<const WaterState*>(currentState)->bottle[0];
	next->bottle[1] = reinterpret_cast<const WaterState*>(currentState)->bottle[1];
	int temp0,temp1;
	switch (action) {
		case FILL_0:
			next->bottle[0] = next->maxsize[0];
			break;
			
		case FILL_1:
			next->bottle[1] = next->maxsize[1];
			break;
			
		case MOVE_0:
			temp0 = next->maxsize[1] - next->bottle[1];
			next->bottle[1] += std::min(temp0, next->bottle[0]);
			next->bottle[0] -= std::min(temp0, next->bottle[0]);
			break;
		
		case MOVE_1:
			temp1 = next->maxsize[0] - next->bottle[0];
			next->bottle[0] += std::min(temp1, next->bottle[1]);
			next->bottle[1] -= std::min(temp1, next->bottle[1]);
			break;
		
		case EMPTY_0:
			next->bottle[0] = 0;
			break;
			
		case EMPTY_1:
			next->bottle[1] = 0;
			break;
			
	}
	return next;
}

bool ProblemWater::goalTest(const State *_state) {
	return reinterpret_cast<const WaterState*>(_state)->bottle[1] == 2;
}

double ProblemWater::pathCost(std::vector<int> path) {
	return path.size();
}

double ProblemWater::stepCost(State *firstState, const int &action, State *secondState) {
	return 1;
}

std::vector<int> ProblemWater::actions(const State *_state) {
	std::vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	return vec;
}

State *ProblemWater::lastState(const State *currentState, const int &action) {
	return nullptr;
}

