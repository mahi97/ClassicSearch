//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "ProblemWater.h"

State* ProblemWater::initialState() {
	return new WaterState(0, 0);
}

State *ProblemWater::initialStateR() {
	return new WaterState(0, 2);
}

State* ProblemWater::nextState(const State *currentState, const int &action) {
	WaterState* next = new WaterState(0, 0);
	next->bottle[0] = dynamic_cast<const WaterState*>(currentState)->bottle[0];
	next->bottle[1] = dynamic_cast<const WaterState*>(currentState)->bottle[1];
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
		default:break;
	}
	next->par = currentState;
	next->act = action;
	return next;
}

State* ProblemWater::nextStateR(const State *currentState, const int &action) {
	WaterState* next = new WaterState(0, 0);
	next->bottle[0] = dynamic_cast<const WaterState*>(currentState)->bottle[0];
	next->bottle[1] = dynamic_cast<const WaterState*>(currentState)->bottle[1];
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
		
		default:break;
	}
	next->par = currentState;
	next->act = action;
	return next;
}

bool ProblemWater::goalTest(const State *_state) {
	return dynamic_cast<const WaterState*>(_state)->bottle[1] == 2;
}

double ProblemWater::pathCost(std::list<int> path) {
	return path.size();
}

double ProblemWater::stepCost(const State *firstState, const int &action,const State *secondState) {
	return 1;
}

std::vector<int> ProblemWater::actions(const State *_state) {
	std::vector<int> vec;
	vec.push_back(FILL_0);
	vec.push_back(FILL_1);
	vec.push_back(MOVE_0);
	vec.push_back(MOVE_1);
	vec.push_back(EMPTY_0);
	vec.push_back(EMPTY_1);
	return vec;
}

bool ProblemWater::goalTestBidirect(const State *_state) {
	return false;
}


