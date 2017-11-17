//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include <iostream>
#include "SearchBFS.h"

SearchBFS::SearchBFS(bool isGraph) : Search(isGraph) {
	
}

void SearchBFS::execute() {
	f.push_back(problem->initialState());
	if (isGraph) searchG();
	else search();
}

void SearchBFS::search() {
	while (! f.empty() ) {
		State* s = f.front();
		f.pop_front();

		if (problem->goalTest(s)) {
			result.answer = s;
			return;
		}
		
		for (auto& action : problem->actions(s)) {
			f.push_back(problem->nextState(s, action));
		}
	}
}

void SearchBFS::searchG() {
	while (! f.empty() ) {
		State* s = f.front();
		f.pop_front();
		if (problem->goalTest(s)) {
			result.answer = s;
			return;
		}
		for (auto& action : problem->actions(s)) {
			bool temp = false;
			for (auto node : e) {
				if (*node == *s) {
					temp = true;
					break;
				}
			}
			if (temp) continue;
			f.push_back(problem->nextState(s, action));
		}
		e.push_back(s);
	}
}
