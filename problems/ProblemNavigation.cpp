//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include <cstdarg>
#include "ProblemNavigation.h"

ProblemNavigation::ProblemNavigation(int n, int m,...) : Problem(), n(n), m(m) {
	std::va_list ap;
	va_start(ap, m);
	for(size_t i = 0; i < n; i++) {
		for(size_t j = 0; j < m; j++) {
			field[i][j] = va_arg(ap, int);
		}
		
	}
	
	va_end(ap);
			
}

State* ProblemNavigation::initialState() {
	return new NavigationState{0, 0};
}

State* ProblemNavigation::nextState(const State *currentState, const int &action) {
	NavigationState* temp= new NavigationState(*reinterpret_cast<const NavigationState*>(currentState));
	switch (action) {
		case MOVE_UP:
			temp->y++;
			break;
		case MOVE_DOWN:
			temp->y--;
			break;
		case MOVE_LEFT:
			temp->x--;
			break;
		case MOVE_RIGHT:
			temp->x++;
			break;
		default:break;
	}
	return temp;
}

bool ProblemNavigation::goalTest(const State *_state) {
	return reinterpret_cast<const NavigationState*>(_state)->x == n-1
			&& reinterpret_cast<const NavigationState*>(_state)->y == m-1;
}

double ProblemNavigation::pathCost(std::vector<int> path) {
	return path.size();
}

double ProblemNavigation::stepCost(State *firstState, const int &action, State* secondState) {
	return 1;
}

std::vector<int> ProblemNavigation::actions(const State *_state) {
	const NavigationState* nav = reinterpret_cast<const NavigationState*>(_state);
	std::vector<int> vec;
	if (nav->x != 0   && field[nav->x-1] != 0) vec.push_back(MOVE_LEFT);
	if (nav->x != n-1 && field[nav->x+1] != 0) vec.push_back(MOVE_RIGHT);
	if (nav->y != 0   && field[nav->y-1] != 0) vec.push_back(MOVE_DOWN);
	if (nav->y != m-1 && field[nav->y+1] != 0) vec.push_back(MOVE_UP);
	return vec;
}