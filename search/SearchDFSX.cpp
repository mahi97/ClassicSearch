//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include <iostream>
#include "SearchDFSX.h"

SearchDFSX::SearchDFSX(bool isGraph, unsigned int depth) : Search(isGraph) {
		this->depth = depth;
}

void SearchDFSX::execute() {
	search();
	if (!result.path.empty())
		result.path.pop_back();
	result.maxMemoryUsage = result.path.size() * sizeof(int);
	result.pathCost = problem->pathCost(result.path);
}

void SearchDFSX::search(State *node, int _depth) {
	if (_depth > this->depth) return;
	
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
		search(problem->nextState(node, action), _depth + 1);
		if (result.answer != nullptr) {
			result.path.push_back(node->act);
			return;
		}
	}
	
}

void SearchDFSX::search() {
	search(problem->initialState(), 0);
}

void SearchDFSX::setDepth(int depth) {
	this->depth = depth;
}


