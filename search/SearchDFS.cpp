//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "SearchDFS.h"

SearchDFS::SearchDFS(bool isGraph) : SearchDFSX(isGraph, INT_MAX) {}

void SearchDFS::execute() {
	SearchDFSX::execute();
}

void SearchDFS::search() {
	search(problem->initialState());
}

void SearchDFS::search(State *node) {
	
	if (problem->goalTest(node)) {
		result.answer = node;
		result.path.push_back(node->act);
		return;
	}
	result.nodeExpand++;
	for (auto& action : problem->actions(node)) {
		if (isGraph) {
			bool temp = false;
			for (auto nod : e) {
				if (*nod == *problem->nextState(node, action)) {
					temp = true;
					break;
				}
			}
			if (temp) continue;
		}
		result.nodeSeen++;
		e.push_back(node);
		search(problem->nextState(node, action));
		if (result.answer != nullptr) {
			result.path.push_back(node->act);
			return;
		}
	}
	
}
