//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include <cstdarg>
#include <iostream>
#include "ProblemNavigation.h"

ProblemNavigation::ProblemNavigation(int n, int m,...) : Problem(), n(n), m(m) {
	field = new int*[n];
	seen[0] = new bool*[n];
	seen[1] = new bool*[n];
	
	for(int i = 0 ; i < n ; i++) field[i] = new int[m];
	for(int i = 0 ; i < n ; i++) seen[0][i] = new bool[m];
	for(int i = 0 ; i < n ; i++) seen[1][i] = new bool[m];
	
	std::va_list ap;
	va_start(ap, m);
	for(size_t i = 0; i < n; i++) {
		for(size_t j = 0; j < m; j++) {
			field[n-i-1][j] = va_arg(ap, int);
			seen[0][n-i-1][j] = false;
			seen[1][n-i-1][j] = false;
		}
	}
	
	va_end(ap);
}

State* ProblemNavigation::initialState() {
	return new NavigationState{0, 0};
}

State *ProblemNavigation::initialStateR() {
	return new NavigationState{m-1, n-1};
}


State* ProblemNavigation::nextState(const State *currentState, const int &action) {
	NavigationState* temp= new NavigationState(*dynamic_cast<const NavigationState*>(currentState));
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
	temp->par = currentState;
	temp->act = action;
	seen[0][temp->y][temp->x] = true;
	return temp;
}

State* ProblemNavigation::nextStateR(const State *currentState, const int &action){
	NavigationState* temp= new NavigationState(*dynamic_cast<const NavigationState*>(currentState));
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
	temp->par = currentState;
	temp->act = action;
	seen[1][temp->y][temp->x] = true;
	return temp;
}

bool ProblemNavigation::goalTest(const State *_state) {
	return dynamic_cast<const NavigationState*>(_state)->x == m-1
			&& dynamic_cast<const NavigationState*>(_state)->y == n-1;
}

double ProblemNavigation::pathCost(std::list<int> path) {
	return path.size();
}

double ProblemNavigation::stepCost(const State *firstState, const int &action,const State* secondState) {
	return 1;
}

std::vector<int> ProblemNavigation::actions(const State *_state) {
	const NavigationState* nav = reinterpret_cast<const NavigationState*>(_state);
	std::vector<int> vec;
	if (nav->x != 0   && field[nav->y][nav->x - 1] != 0) vec.push_back(MOVE_LEFT);
	if (nav->x != m-1 && field[nav->y][nav->x + 1] != 0) vec.push_back(MOVE_RIGHT);
	if (nav->y != 0   && field[nav->y - 1][nav->x] != 0) vec.push_back(MOVE_DOWN);
	if (nav->y != n-1 && field[nav->y + 1][nav->x] != 0) vec.push_back(MOVE_UP);
	return vec;
}

double ProblemNavigation::h(const State * _state) {
	return (m - 1 - dynamic_cast<const NavigationState*>(_state)->x) + (n - 1 - dynamic_cast<const NavigationState*>(_state)->y);
}

bool ProblemNavigation::goalTestBidirect(const State *_state) {
	const NavigationState* temp = dynamic_cast<const NavigationState*>(_state);
	return (seen[0][temp->y][temp->x] & seen[1][temp->y][temp->x]);
}
