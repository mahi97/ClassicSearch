//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include <iostream>
#include <fstream>
#include "ProblemPuzzle.h"

State* ProblemPuzzle::initialState() {
	PuzzleState* p = new PuzzleState(
			9,
			0, 2, 5,
			1, 4, 8,
			3, 6, 7
	);
	return p;
}

State* ProblemPuzzle::initialStateR() {
	PuzzleState* p = new PuzzleState(
			9,
			0, 1, 2,
			3, 4, 5,
			6, 7, 8
	);
	return p;
}

State* ProblemPuzzle::nextState(const State* currentState, const int &action) {
	int i;
	for (i = 0; i < 9; i++) if (dynamic_cast<const PuzzleState*>(currentState)->puzzle[i] == 0) break;
	PuzzleState* temp= new PuzzleState(*dynamic_cast<const PuzzleState*>(currentState));
	swapPuzzle(i, action, temp);
	temp->par = currentState;
	temp->act = action;
	return temp;
}

State* ProblemPuzzle::nextStateR(const State *currentState, const int &action){
	int i;
	for (i = 0; i < 9; i++) if (dynamic_cast<const PuzzleState*>(currentState)->puzzle[i] == 0) break;
	PuzzleState* temp= new PuzzleState(*dynamic_cast<const PuzzleState*>(currentState));
	swapPuzzle(i, action, temp);
	temp->par = currentState;
	temp->act = action;
	return temp;
}

bool ProblemPuzzle::goalTest(const State* _state) {
	
	for (int i = 0; i < 9 ; i++) if (dynamic_cast<const PuzzleState*>(_state)->puzzle[i] != i) return false;
	return true;
}

double ProblemPuzzle::pathCost(std::list<int> path) {
	return path.size();
}

double ProblemPuzzle::stepCost(const State* firstState, const int &action, const State* secondState) {
	return 1;
}

std::vector<int> ProblemPuzzle::actions(const State* _state) {
	std::vector<int> vec;
	int i;
	for (i = 0; i < 9; i++) if (dynamic_cast<const PuzzleState*>(_state)->puzzle[i] == 0) break;
	if (i < 6)      vec.push_back(UP);
	if (i >= 3)     vec.push_back(DOWN);
	if (i % 3 != 2) vec.push_back(LEFT);
	if (i % 3 != 0) vec.push_back(RIGHT);
	return vec;
}

void ProblemPuzzle::swapPuzzle(int i, int action, PuzzleState* _puzzle) {
	switch (action) {
		case UP:
			if (i < 6) std::swap(_puzzle->puzzle[i], _puzzle->puzzle[i+3]);
			break;
		case DOWN:
			if (i >= 3) std::swap(_puzzle->puzzle[i], _puzzle->puzzle[i-3]);
			break;
		case LEFT:
			if (i % 3 != 2) std::swap(_puzzle->puzzle[i], _puzzle->puzzle[i+1]);
			break;
		case RIGHT:
			if (i % 3 != 0) std::swap(_puzzle->puzzle[i], _puzzle->puzzle[i-1]);
			break;
		default:break;
	}
}

double ProblemPuzzle::h(const State *_state) {
	const PuzzleState* p = dynamic_cast<const PuzzleState*>(_state);
	double h = 0.0;
	for (int  i = 0; i < 9 ; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == p->puzzle[j]) {
				h += std::abs(j/3 - i/3);
				h += std::abs(j%3 - i%3);
				break;
			}
		}
	}
	return h;
}

bool ProblemPuzzle::goalTestBidirect(const State *_state) {
	return false;
}
