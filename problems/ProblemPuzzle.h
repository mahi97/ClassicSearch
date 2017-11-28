//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_PROBLEMPUZZLE_H
#define SEARCH_PROJECT_PROBLEMPUZZLE_H


#include <Problem.h>
#include <cstdarg>

enum PuzzleAction {
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

class PuzzleState : public State {
public:
	PuzzleState(int n,...) {
		std::va_list ap;
		va_start(ap, n);
		for(size_t i = 0; i < 9; i++) {
				puzzle[i] = va_arg(ap,int);
			
		}
		
		va_end(ap);
	}
	bool operator==(const State& _other) const {
		for (int i = 0; i < 9 ; i++) {
			if (puzzle[i] != reinterpret_cast<const PuzzleState&>(_other).puzzle[i]) {
				return false;
			}
		}
		return true;
	}
	int puzzle[9];
};

class ProblemPuzzle : public Problem {
	virtual State* initialState();
	virtual State* initialStateR();
	virtual State* nextState(const State* currentState, const int& action);
	virtual State* nextStateR(const State* currentState, const int& action);
	virtual bool goalTest(const State* _state);
	virtual bool goalTestBidirect(const State* _state);
	virtual double pathCost(std::list<int> path);
	virtual std::vector<int> actions(const State* _state);
	virtual double stepCost(const State* firstState, const int& action, const State* secondState);
	virtual double h(const State*);

private:
	void swapPuzzle(int i, int action, PuzzleState*);
	
};


#endif //SEARCH_PROJECT_PROBLEMPUZZLE_H
