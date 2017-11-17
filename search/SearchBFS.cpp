//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "SearchBFS.h"

SearchBFS::SearchBFS(bool isGraph) : Search(isGraph) {
	
}

void SearchBFS::execute() {
	f.push(problem->initialState());
	if (isGraph) searchG();
	else search();
}

void SearchBFS::search() {
	while (! f.empty() ) {
		State* s = f.front();
		f.pop();
		if (problem->goalTest(s)) {
			result.answer = s;
			return;
		}
		
		for (auto& action : problem->actions(s)) {
			f.push(problem->nextState(s, action));
		}
		search();
		
	}
}

void SearchBFS::searchG() {
	while (! f.empty() ) {
		State* s = f.front();
		f.pop();
		if (problem->goalTest(s)) {
			result.answer = s;
			return;
		}
		
		for (auto& action : problem->actions(s)) {
			for (auto node : e) if (node == s) continue;
			f.push(problem->nextState(s, action));
		}
		e.push_back(s);
		search();
		
	}
}
